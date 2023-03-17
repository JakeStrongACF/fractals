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

    int xp,yp;
    double x,y;
    complex c,z;
    double first[2];
    double second[2];

    for(yp = 0; yp < 600; yp++)
    {
        for(xp = 0; xp < 600; xp++)
        {
            x = xp * 2.0/600 - 2;
            y = yp * 2.0/600 - 2;
            c = x*3 + y*3*I;
            z = 0;

            int i = 0;

            while(i <= 256)
            {
                z = cpow(z,25.0) + c;

                ++i;
            }
              

            if(cabs(z) < 100)
            {
                G_rgb(1/cabs(z),1*cabs(z),0);
                G_point (xp, yp);
            }
        }       
    }

    double r[2];
    G_wait_click(r);
}