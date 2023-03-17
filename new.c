#include "FPToolkit.c"

double x[1] = {300};
double y[1] = {300};


void translate (double dx, double dy)
{
  int i ;

  i = 0 ;
  while (i < 1) {
    x[i] = x[i] + dx ;
    y[i] = y[i] + dy ;
    i = i + 1 ;
  }
}
void scale (double sx, double sy)
{
  int i ;

  i = 0 ;
  while (i < 1) {
    x[i] = x[i] * sx ;
    y[i] = y[i] * sy ;
    i = i + 1 ;
  }
}

void rotate (double t)
{
  int i ;
  t = t * (M_PI/180);
    
  i = 0 ;
  double c = cos(t);
  double s = sin(t);
  double temp;
  while (i < 1) {
    temp = x[i] * c - y[i] * s ;
    y[i] = x[i] * s + y[i] * c ;
    x[i] = temp;
    i = i + 1 ;
  }
}

void koch_curve(double r)
{
    if(r < 0.25)
    {
        scale(0.333, 0.333);
        G_rgb(r*100,r*100,0);
        
    }
    
    else if(r < 0.5)
    {
        scale(0.333, 0.333);
        rotate(60);
        translate(0.333,0.0);
        G_rgb(0,r*100,0);
    }

    else if(r < 0.75)
    {
        scale(0.333, 0.333);
        rotate(-60);
        translate(0.5,0.2886);
        G_rgb(0,0,r*100);
    }

    else
    {
        scale(0.333, 0.333);
        translate(0.666,0.0);
        G_rgb(r*100,r*100,r*100);
    }
}

int main()
{
    G_init_graphics(601, 601) ;
    G_rgb(1,0.5,0.5);
    G_clear() ;

    G_rgb(0,1,0.5);

    
    srand48(200);


    int n = 5000000;
    int size = 601;

    double j = 0;
    double r = 0;
    while(j < n)
    {
        r = drand48();
        koch_curve(r);
        G_point (x[0] * size, y[0] * size);

        j = j + 1;
    }

    double z[2];
    G_wait_click(z);  

    G_save_to_bmp_file("curve.bmp") ;
}