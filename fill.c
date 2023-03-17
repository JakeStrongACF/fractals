#include "FPToolkit.c"

// appropriate for a 600x600 window
//double x[13] = {263,338,338,450,338,338,375,300,225,263,263,150,263} ;
//double y[13] = {450,450,375,338,338,300,150,263,150,300,338,338,375} ;
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
void filled_triangle(double r)
{
    if(r < 0.5)
    {
        scale(sqrt(2)/2,sqrt(2)/2);
        rotate(225);
        translate(0.5,0.5);
    }

    else
    {
        scale(sqrt(2)/2,sqrt(2)/2);
        rotate(135);
        translate(0.5,0.5);
    }
}
void s_gasket(double r)
{
    if(r < 0.333)
    {
        scale(0.5,0.5);
    }
        
    else if(r < 0.666)
    {
        scale(0.5,0.5);
        translate(0.5,0.0);     
    }

    else
    {
        scale(0.5,0.5);
        translate(0.0,0.5);
    }
}

void filled_squares(double r)
{
    if(r < 0.1)
    {
        scale(0.333,0.333);
        translate(0.0,0.0);
    }
    
    else if(r < 0.2)
    {
        scale(0.333,0.333);
        translate(0.333,0.0);
    }

    else if(r < 0.3)
    {
        scale(0.333,0.333);
        translate(0.666,0.0);
    }

    else if(r < 0.4)
    {
        scale(0.333,0.333);
        translate(0.0,0.333);
    }

//    else if(r < 0.5)
//    {
//        scale(0.333,0.333);
//        translate(0.333,0.333);
//    }

    else if(r < 0.6)
    {
        scale(0.333,0.333);
        translate(0.666,0.333);
    }

    else if(r < 0.7)
    {
        scale(0.333,0.333);
        translate(0.0,0.666);
    }

    else if(r < 0.8)
    {
        scale(0.333,0.333);
        translate(0.333,0.666);
    }

    else
    {
        scale(0.333,0.333);
        translate(0.666,0.666);
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

void trek(double r)
{
    if(r < 0.333)
    {
        translate(0.0,-0.5);
        scale(0.5, 0.5);
        translate(0.0,0.5);
        G_rgb(0,1,0);
        
    }

    else if(r < 0.666)
    {
        translate(-0.5,0.0);
        scale(0.5, 0.5);
        rotate(90);
        translate(0.5,0.0);
        G_rgb(0,1,1);
        
    }

    else
    {
        translate(0.0,-0.5);
        scale(0.5, 0.5);
        rotate(180);
        translate(0.0,0.5); 
        G_rgb(0,0,1);
    }    
}

void initial(double r)
{
    ///// J
    if(r < (1/15))
    {
        scale(0.1666,0.125);
        translate(2.0/36,0.0);
        
    } 

    else if(r < (2/15))
    {
        scale(0.1666,0.125);
        rotate(90);
        translate(4.0/36,0.0);
        
    }

    else if(r < (3/15))
    {
        scale(0.1666,0.125);
        rotate(90);
        translate(8.0/36, 2.0/16);
        
    }

    else if(r < (4/15))
    {
        scale(0.1666,0.125);
        rotate(90);
        translate(8.0/36,8.0/16);
        
    }

    ////// R
    else if(r < (5/15))
    {
        scale(0.1666,0.125);
        rotate(90);
        
    }

    else if(r < (6/15))
    {
        scale(0.1666,0.125);
        rotate(90);
        
    }

    else if(r < (7/15))
    {
        scale(0.1666,0.125);
        
    }

    else if(r < (8/15))
    {
        scale(0.1666,0.125);
        
    }

    else if(r < (9/15))
    {
        scale(0.1666,0.125);
        rotate(90);
        
    }

    else if(r < (10/15))
    {
        scale(0.1666,0.125);
        rotate(45);
        
    }

    /////// S
    else if(r < (11/15))
    {
        scale(0.1666,0.125);
        
    }

    else if(r < (12/15))
    {
        scale(0.1666,0.125);
        rotate(90);
        
    }

    else if(r < (13/15))
    {
        scale(0.1666,0.125);
        
    }

    else if(r < (14/15))
    {
        scale(0.1666,0.125);
        rotate(90);
        
    }

    else
    {
        scale(0.1666,0.125);
        
    } 

}

void ferns(double r)
{
    if(r < 0.01)
    {
        translate(-0.5,0);
        rotate(-2.678);
        scale(0.849,0.849);
        translate(0,0.160); 
    }

    else if(r < 0.86)
    {
        translate(-0.5,0);
        rotate(51.418);
        scale(0.335,0.335);
        translate(0,0.160);    
    }

    else if(r < 0.93)
    {   
        translate(-0.5,0);
        rotate(52.462);
        scale(-0.383,0.383);
        translate(0,0.040);   
    }

    else
    {
        translate(-0.5,0);
        rotate(14.715);
        scale(0,0.156);
        translate(0,0);
        
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
//        filled_triangle(r);
//        s_gasket(r);
//        filled_squares(r);
        koch_curve(r);
//        trek(r);
//        initial(r);
//        ferns(r);
        G_point (x[0] * size, y[0] * size);

        j = j + 1;
    }

    double z[2];
    G_wait_click(z);     
}