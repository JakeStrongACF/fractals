#include  "FPToolkit.c"

int main()
{
    int    swidth, sheight ;

    swidth = 600;  sheight = 600;
    G_init_graphics (swidth,sheight);

    int d;

    printf("Type a d for depth  \n");

    scanf("%d", &d);

    G_rgb (0.5, 0.5, 0.5);
    G_clear ();

    double p0x = 10;
    double p0y = 10;
    double p1x = 590;
    double p1y = 10;
    double p2x = 300;
    double p2y = 590;
    double i = 0;

    while(i <= d)
    {
        G_rgb (0.0, 1.0, 0.0) ; 
        G_triangle (p0x,p0y  ,  p1x,p1y  ,  p2x,p2y);

        
        ++i;
    }

    int key;   
    key =  G_wait_key() ;
    
}