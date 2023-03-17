#include  "FPToolkit.c"

int main()
{
    int    swidth, sheight ;

    swidth = 600;  sheight = 600;
    G_init_graphics (swidth,sheight);

    double n;

    printf("Type an n for the depth of the triangles \n");

    scanf("%lf", &n);

    G_rgb (0.5, 0.5, 0.5);
    G_clear ();

    printf("click three points\n");

    double x[2];
    double y[2];
    double z[2];

    G_rgb(1,0,0);

    G_wait_click(x);
    G_fill_circle(x[0],x[1],4);

    G_wait_click(y);
    G_fill_circle(y[0],y[1],4);

    G_wait_click(z);
    G_fill_circle(z[0],z[1],4);

    G_rgb(0,1,0.5) ;
    G_line(x[0],x[1], y[0],y[1]) ;

    G_rgb(0,1,0.5) ;
    G_line(y[0],y[1], z[0],z[1]) ;

    G_rgb(0,1,0.5) ;
    G_line(z[0],z[1], x[0],x[1]) ;

    make_triangles(double x, double y, double z, int d)



    int key ;   
    key =  G_wait_key() ;

}
