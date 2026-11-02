enum OID { OID_Nil };
struct ALO { char pad[0x74]; float t74; };
struct BL { int x0; ALO *palo; };
struct MRSG { float t; float dt; };
extern "C" float TFindAsegLabel__FP4ASEG3OID(ALO *palo, OID oid);
void FillBlAmrsg(int cbBl, int cbl, void *pbl, int ibAmrsg, int coid, OID *aoid)
{
    int ibl;
    for (ibl = 0; ibl < cbl; ibl++) {
        BL *pblT = (BL *)((char *)pbl + ibl * cbBl);
        ALO *palo = pblT->palo;
        if (palo) {
            MRSG *amrsg = (MRSG *)((char *)pblT + ibAmrsg);
            MRSG *pmrsgPrev;
            MRSG *pmrsg;
            int i;
            pmrsg = amrsg;
            for (i = 0; i < coid; i++, pmrsg++)
                pmrsg->t = TFindAsegLabel__FP4ASEG3OID(palo, aoid[i]);
            pmrsg = amrsg;
            pmrsgPrev = &pmrsg[coid - 1];
            for (i = 0; i < coid; i++, pmrsg++) {
                float dt = pmrsg->t - pmrsgPrev->t;
                pmrsgPrev->dt = dt;
                if (dt < 0.0f)
                    pmrsgPrev->dt = dt + palo->t74;
                pmrsgPrev = pmrsg;
            }
        }
    }
}
