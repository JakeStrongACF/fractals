#include  "FPToolkit.c"

void background()
{
    double p1[2];
    double p2[2];

    p1[0] = 0.0;
    p1[1] = 0.0;
    p2[0] = 599.0;
    p2[1] = 0.0;

    double i = 0.0;
    while(i < 600)
    {
        p1[1] = p1[1] + 1;
        p2[1] = p2[1] + 1;
        G_rgb((255-i/2)/255,(0.0+i/2)/255,(0.0+i)/255);
        G_line(p1[0],p1[1],p2[0],p2[1]);
        ++i;
    }   
}

void circle(double x, double y, double r, int depth)
{
    G_rgb (1, 0, 0);
    G_circle (x, y, r);

    if(depth % 2 == 0)
    {
        G_rgb (0, 0, 0);
        G_fill_circle (x, y, r);  
    }
    else
    {
        G_rgb (1, 1, 0);
        G_fill_circle (x, y, r);   
    }
        
    if(depth > 1)
    {
        circle(x,y-r/2,r/2,depth-1);
        circle(x+r/2,y,r/2,depth-1);
        circle(x-r/2,y,r/2,depth-1);
    }
}

int main()
{
    int    swidth, sheight ;

    swidth = 600;  sheight = 600;
    G_init_graphics (swidth,sheight);

    int n;

    printf("Type a depth. \n");

    scanf("%d", &n);

    G_rgb (0.5, 0.5, 0.5);
    G_clear ();

    background();

    circle(swidth/2,sheight/2,300,n);

    double z[2];
    G_wait_click(z) ; 

    G_save_to_bmp_file("batmerica.bmp") ;
}