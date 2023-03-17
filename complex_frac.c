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

    for(yp = 0; yp < 600; yp++)
    {
        for(xp = 0; xp < 600; xp++)
        {
            x = xp * 4.0/600 - 2;
            y = yp * 4.0/600 - 2;
            c = x + y*I;
            z = 0;

            int i = 0;
            int j = 0;
            int f = 0;

            while(i <= 255)
            {
                z = cpow(z,5.0) + c;

                ++i;

                if(cabs(z) > 100 && f == 0)
                {
                    j = i;
                    f = 1;
                }
            }
              

            if(cabs(z) < 100)
            {
                G_rgb(0,1*cabs(z),0);
                G_point (xp, yp);
            }

            else
            {
                G_rgb(j/255.0,j/255.0,0);
                G_point (xp, yp);   
            }

        }       
    }

    double r[2];
    G_wait_click(r);

    G_save_to_bmp_file("complex.bmp") ;
}