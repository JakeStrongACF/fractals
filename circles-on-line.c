#include  "FPToolkit.c"

int main()
{
    int    swidth, sheight ;

    swidth = 600;  sheight = 600;
    G_init_graphics (swidth,sheight);

    double n;

    printf("Type an n for the number of circles \n");

    scanf("%lf", &n);

    G_rgb (0.5, 0.5, 0.5);
    G_clear ();

    double p[2];

    G_rgb(1,0,0);

    G_wait_click(p);
    G_fill_circle(p[0],p[1],4);

    double q[2];

    G_wait_click(q);
    G_fill_circle(q[0],q[1],4);

    G_rgb(0,1,0.5) ;
    G_line(p[0],p[1], q[0],q[1]) ;

    double d = sqrt(((q[0]-p[0])*(q[0]-p[0]))+((q[1]-p[1])*(q[1]-p[1])));

    double i = 1;
    double j = 1;
    double num_r = n*2.0;
    double r = d/num_r;

    while(i <= n)
    {
        double t = j/(2*n);

        double x = p[0] + t*(q[0]-p[0]);
        double y = p[1] + t*(q[1]-p[1]);
        

        G_rgb(0,t,0);

        G_fill_circle(x,y,r);

        ++i;
        j = j + 2;
    }
    
    int key ;   
    key =  G_wait_key() ;
}