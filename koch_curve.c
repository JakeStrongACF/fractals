#include "FPToolkit.c"

void koch_curve(double p1[], double p2[], double d, double angle)
{
    if(d == 0)
        return;
    else
    {
        double p3[2];
        double p4[2];
        double p5[2];
        double t = angle * M_PI/180;

        p3[0] = (2 * p1[0] + p2[0])/3;
        p3[1] = (2 * p1[1] + p2[1])/3;
        p5[0] = (2 * p2[0] + p1[0])/3;
        p5[1] = (2 * p2[1] + p1[1])/3;
        p4[0] = p3[0] + (p5[0] - p3[0])*cos(t) + (p5[1] - p3[1])*sin(t);
        p4[1] = p3[1] - (p5[0] - p3[0])*sin(t) + (p5[1] - p3[1])*cos(t);
            

            
        koch_curve(p1,p3,d-1,angle);
		koch_curve(p3,p4,d-1,angle);
		koch_curve(p4,p5,d-1,angle);
		koch_curve(p5,p2,d-1,angle);

        G_line(p1[0],p1[1], p2[0],p2[1]); 
        return;
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

    G_rgb (0.5, 0.5, 0.5);
    G_clear ();

    double p1[2];
    double p2[2];
    double p3[2];
    double p4[2];
    

    G_rgb (1, 0, 0);

    p1[0] = 0.0;
    p1[1] = 0.0;

    p2[0] = 599.0;
    p2[1] = 0.0;

    p3[0] = 599.0;
    p3[1] = 599.0;

    p4[0] = 0.0;
    p4[1] = 599.0;

    koch_curve(p2,p1,d,60);
    koch_curve(p3,p2,d,60);
    koch_curve(p4,p3,d,60);
    koch_curve(p1,p4,d,60);

    double z[2];
    G_wait_click(z) ;

    G_save_to_bmp_file("demo.bmp") ;

}

