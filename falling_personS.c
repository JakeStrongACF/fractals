#include "FPToolkit.c"

// appropriate for a 600x600 window
double x[13] = {263,338,338,450,338,338,375,300,225,263,263,150,263} ;
double y[13] = {450,450,375,338,338,300,150,263,150,300,338,338,375} ;
int n = 13 ;


void translate (double dx, double dy)
{
  int i ;

  i = 0 ;
  while (i < n) {
    x[i] = x[i] + dx ;
    y[i] = y[i] + dy ;
    i = i + 1 ;
  }
}
void scale (double sx, double sy)
{
  int i ;

  i = 0 ;
  while (i < n) {
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
  while (i < n) {
    temp = x[i] * c - y[i] * s ;
    y[i] = x[i] * s + y[i] * c ;
    x[i] = temp;
    i = i + 1 ;
  }
}






int main() 
{
  int q ;

  G_init_graphics(601, 601) ;
  G_rgb(0,0,0) ;
  G_clear() ;
 
  G_rgb(0,0,1) ; G_fill_polygon(x,y,n) ;
  double z[2];
  G_wait_click(z);
  
  for(int i = 0; i < 125; ++i)
  {
  translate(-300,-300) ;
  scale(.97,.97);
  rotate(10);
  translate(300,300) ;
  G_rgb(0,0,0) ;
  G_clear();
  G_rgb(0,0,1) ; G_fill_polygon(x,y,n) ;
  G_display_image();
  usleep(40000) ; 
  }
  
 
  G_rgb(1,0,0) ; G_fill_circle(300,300,10) ;
  G_wait_click(z) ;
}

