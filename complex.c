#include <stdio.h>
#include <math.h>
#include <complex.h>
#include "FPToolkit.c"


int main()
{

    G_init_graphics(601, 601) ;
    G_rgb(1,1,1);
    G_clear() ;

    G_rgb(0,1,0);

    
    complex com = 0.5;

    complex z = 0;

    int i = 0;

    while(i <= 1000)
    {
        z = cpow(z,2.0) + com;

       G_point (z, z); 

        ++i;
    }

    

    printf("%lf + %lfi \n", creal(z), cimag(z));

    complex a,b,c,d,e,f;

    a = 3 + 4*I;
    b = 2 -7*I;
    c = a + b;
    d = a - b;
    e = a * b;
    f = b/a;

    printf("%lf + %lfi \n", creal(e), cimag(e));
    printf("%lf + %lfi \n", creal(f), cimag(f));

    double r[2];
    G_wait_click(r);
       
}