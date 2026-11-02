#!/usr/bin/env python3
"""Remove matching-process bookkeeping from comments in src/ (who matched what, in which lane/wave, on which day).

  clean_history.py [--dry-run]

Only comments are touched, and only:
  - attribution groups such as "(Claude agent)", "(Claude agent, lane A9, 2026-10-23)", "(w2lane4, wave 2)"
  - "// history: ..." lines (attempt logs; the git history keeps them)
Technical notes (why a register pin or an asm statement is needed) are kept.  Who did the work is in CREDITS.md.
"""
import os, re, sys, glob

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ATTR = re.compile(r'\s*\((?:Claude agent|lane ?[A-Z]?\d|wave[ -]?\d|w\dlane|probe)[^()]*\)')
HIST_LINE = re.compile(r'^[ \t]*// history:[^\n]*\n', re.M)
COMMENT = re.compile(r'//[^\n]*|/\*.*?\*/', re.S)


def clean(t):
    t = HIST_LINE.sub('', t)
    def fix(m):
        c = m.group(0)
        c2 = ATTR.sub('', c)
        if c2 == c: return c
        c2 = re.sub(r'^(//|/\*)\s*:\s*', r'\1 ', c2)              # "// (Claude agent): note" -> "// note"
        if re.fullmatch(r'/\*\s*\*/', c2): return ' '                # nothing left of a /* */ comment
        if re.fullmatch(r'//\s*', c2): return '\0'                    # nothing left of a // comment: drop the line below
        return c2
    t = COMMENT.sub(fix, t)
    t = re.sub(r'^[ \t]*\0\n', '', t, flags=re.M)                      # comment-only line that became empty
    return re.sub(r'[ \t]*\0', '', t)


def main():
    dry = '--dry-run' in sys.argv
    n = 0
    for p in sorted(glob.glob(os.path.join(ROOT, 'src', '**', '*.c*'), recursive=True)):
        if not p.endswith(('.c', '.cpp')): continue
        t = open(p, encoding='utf-8', errors='surrogateescape').read()
        u = clean(t)
        if u != t:
            n += 1
            if dry: print(os.path.relpath(p, ROOT))
            else: open(p, 'w', encoding='utf-8', errors='surrogateescape').write(u)
    print(f'{n} file(s) {"would be " if dry else ""}cleaned')


if __name__ == '__main__':
    main()
