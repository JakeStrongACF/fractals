#include  "FPToolkit.c"

int main()
{
    int    swidth, sheight ;

    swidth = 600;  sheight = 600;
    G_init_graphics (swidth,sheight);

    double n;

    printf("Type an n for the number of points in the polygon \n");

    scanf("%lf", &n);

    G_rgb (0.5, 0.5, 0.5);
    G_clear ();

    double x[2];
    double y[2];

    G_rgb (1, 0, 0);

    G_wait_click(x);
    G_fill_circle(x[0],x[1],4);

    G_wait_click(y);
    G_fill_circle(y[0],y[1],4);

    double r = sqrt(((y[0]-x[0])*(y[0]-x[0]))+((y[1]-x[1])*(y[1]-x[1])));

    G_rgb (0.5, 0.5, 0.5);
    G_clear ();

    G_rgb (1, 0, 0);

    G_circle (x[0], x[1], r);


    for(double i=0; i<n; ++i)
    {
        
            
    }
      
    int key;   
    key =  G_wait_key();
}