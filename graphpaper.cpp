// Your graph paper code goes below

#include  "FPToolkit.c"

int main()
{
    int    swidth, sheight ;

    swidth = 600;  sheight = 600;
    G_init_graphics (swidth,sheight);

    int n;

    printf("Type an n for nxn \n");

    scanf("%d", &n);

    G_rgb (0.5, 0.5, 0.5);
    G_clear ();

    double s;

    s = 600/n;
    double x = 0;
    while(x < 600)
    {
        G_rgb (0.0, 1.0, 0.0);
        G_line (0,x,600,x);
        x = x+s;
    }    

    x = 0;

    while(x < 600)
    {
        G_rgb (0.0, 1.0, 0.0);
        G_line (x,0,x,600);
        x = x+s;
    }

    int key;   
    key =  G_wait_key() ;
}