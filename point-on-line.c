#include  "FPToolkit.c"

int main()
{
    int    swidth, sheight ;

    swidth = 600;  sheight = 600;
    G_init_graphics (swidth,sheight);

    int n;

    printf("Type an n for the number of inbetween points \n");

    scanf("%d", &n);

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

    int i = 1;

    while(i <= n)
    {
        double t = 1.0*i/n;

        double x = p[0] + t*(q[0]-p[0]);
        double y = p[1] + t*(q[1]-p[1]);

        G_rgb(0,t,0);

        G_fill_circle(x,y,4);

        ++i;
    }
    
    int key ;   
    key =  G_wait_key() ;

}