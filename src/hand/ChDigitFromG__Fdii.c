extern unsigned char D_002C40C8[];
double func_002452C0(double, double);
double func_0011D740(double);
double func_0023D808(double,double);
double func_0023D7A0(double,double);
double func_0023DD80(int);
int func_0023DE38(double);
/* Digit of g at decimal position a (precision b): 0 outside [b, b+15). */
unsigned char ChDigitFromG__Fdii(double g, int a, int b)
{
int i; double x;
    if (a < b || a - 15 >= b) i = 0;
    else {
        x = func_0011D740(func_0023D808(g, func_002452C0(10.0, func_0023DD80(-b))));
        i = func_0023DE38(func_0023D7A0(x, func_0023D808(func_0011D740(func_0023D808(x, 0.1)), 10.0)));
    }
    return D_002C40C8[i];
}
