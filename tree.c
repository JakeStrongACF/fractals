#include <stdio.h>
#include <math.h>
#include <complex.h>
#include "FPToolkit.c"

void make_ground()
{
    double p1[2];
    double p2[2];

    p1[0] = 0.0;
    p1[1] = 0.0;
    p2[0] = 599.0;
    p2[1] = 0.0;

    int i = 0;
    while(i < 50)
    {
        p1[1] = p1[1] + 1;
        p2[1] = p2[1] + 1;
        G_rgb((144.0-i)/255,(238.0-i)/255,(144.0-i)/255);
        G_line(p1[0],p1[1],p2[0],p2[1]);
        ++i;
    }

    
}
void make_sun()
{
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
}

void draw_tree(double p1[],double angle, double depth)
{
    double fork_angle = 20.0;
    double len = 4.0;
    if(depth == 1)
        G_rgb (0, 1, 0);
    else
        G_rgb (155.0/255, 103.0/255, 60.0/255);
    
    if(depth > 0)
    {
        double p2[2];
        p2[0] = p1[0] + cos((angle * M_PI/180))*depth*len;
        p2[1] = p1[1] + sin((angle * M_PI/180))*depth*len;
        G_line(p2[0],p2[1],p1[0],p1[1]);
        draw_tree(p2, angle - fork_angle, depth -1 );
        draw_tree(p2, angle + fork_angle, depth -1 );
        
    }    
}

int main()
{
    int    swidth, sheight ;

    swidth = 600;  sheight = 600;
    G_init_graphics (swidth,sheight);

    double d;

    printf("Type a d for the depth \n");

    scanf("%lf", &d);

    G_rgb (0.3, 0.8, 0.9);
    G_clear ();

    make_ground();
    make_sun();

    double p1[2];
    double p2[2];
    double p3[2];
    double p4[2];
    

    G_rgb (155.0/255, 103.0/255, 60.0/255);

    p1[0] = 300.0;
    p1[1] = 20.0;

    p2[0] = 300.0;
    p2[1] = 60.0;

    G_line(p1[0],p1[1],p2[0],p2[1]);

    draw_tree(p2,90,d);


    double z[2];
    G_wait_click(z) ;

    G_save_to_bmp_file("demo.bmp") ;
}