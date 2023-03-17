#include "FPToolkit.c"

/*

       Y+
       |
       |    * (y,z)
       |  
<------+--------Z+
   D   |
       |
       |


y'    y
- =  ---
D    D+z

H = D*tan(halfangle) ;

with the x-axis perpendicular to this plane.

*/

#define M 700000
double Wsize = 600  ; // window size ... choose 600 for repl
double X[M],Y[M],Z[M] ;
double Xplot[M],Yplot[M] ;
int N = 0 ;


int translate(double dx, double dy, double dz) 
{
  int i ;

  for (i = 0 ; i < N ; i++) {
    X[i] += dx ;
    Y[i] += dy ;
    Z[i] += dz ;    
  }
}



int rotate_x(double degrees)
// Y[] and Z[] will change but X[] will be unchanged
{
  double radians,c,s,temp ;
  int i ;
  
  radians = degrees*M_PI/180 ;
  c = cos(radians) ;
  s = sin(radians) ;
  for (i = 0 ; i < N ; i++) {
    temp =  c*Y[i] - s*Z[i] ;
    Z[i] =  s*Y[i] + c*Z[i] ;
    Y[i] = temp ;
  }
}




int rotate_y(double degrees)
// X[] and Z[] will change but Y[] will be unchanged
{
  double radians,c,s,temp ;
  int i ;
  
  radians = degrees*M_PI/180 ;
  c = cos(radians) ;
  s = sin(radians) ;
  for (i = 0 ; i < N ; i++) {
    temp =  c*X[i] + s*Z[i] ;
    Z[i] = -s*X[i] + c*Z[i] ;
    X[i] = temp ;
  }
}



int rotate_z(double degrees)
// X[] and Y[] will change but Z[] will be unchanged
{
  double radians,c,s,temp ;
  int i ;
  
  radians = degrees*M_PI/180 ;
  c = cos(radians) ;
  s = sin(radians) ;
  for (i = 0 ; i < N ; i++) {
    temp =  c*X[i] - s*Y[i] ;
    Y[i] =  s*X[i] + c*Y[i] ;
    X[i] = temp ;
  }
}



int project(double observer_distance, double halfangle_degrees)
{
    double angle = halfangle_degrees * M_PI/180;
    double H = observer_distance * tan(angle);
    int i;
    for(i = 0; i < N ; ++i)
    {
        Xplot[i] = observer_distance * X[i] / (observer_distance + Z[i]) * (Wsize/(2.0*H)) + (Wsize/2.0) ;

        Yplot[i] = observer_distance * Y[i] / (observer_distance + Z[i]) * (Wsize/(2.0*H)) + (Wsize/2.0);
    }
}


int draw()
{
  int i ;
  for (i = 0 ; i < N ; i=i+2) {
    G_line(Xplot[i],Yplot[i],  Xplot[i+1],Yplot[i+1]) ;
  }

}



int print_object()
{
  int i ;
  for (i = 0 ; i < N ; i=i+2) {
    printf("(%lf, %lf, %lf)   (%lf, %lf, %lf)\n", 
	   X[i],Y[i],Z[i],  X[i+1],Y[i+1],Z[i+1]) ;
  }

  printf("===============================\n") ;
  
  for (i = 0 ; i < N ; i=i+2) {
    printf("(%lf, %lf)   (%lf, %lf)\n", 
	   Xplot[i],Yplot[i],  Xplot[i+1],Yplot[i+1]) ;
  }  
}



int save_line(double xs, double ys, double zs,
	      double xe, double ye, double ze)
{
  // about to add items at slots N and N+1 :
  if (N+1 >= M) {
    printf("full\n") ;
    return 0 ;
  }
  
  X[N] = xs ; Y[N] = ys ; Z[N] = zs ; N++ ;
  X[N] = xe ; Y[N] = ye ; Z[N] = ze ; N++ ;

  return 1 ;
}

void tri(double x0, double y0, double z0, double x1, double y1, double z1, double x2, double y2, double z2)
{
    save_line(x0,y0,z0, x1,y1,z1);
    save_line(x1,y1,z1, x2,y2,z2);
    save_line(x2,y2,z2, x0,y0,z0);
}

void sier3d(double x0, double y0, double z0, double x1, double y1, double z1, double x2, double y2, double z2, int depth)
{
    if(depth == 0)
        return;

    save_line(x0,y0,z0, x1,y1,z1);
    save_line(x1,y1,z1, x2,y2,z2);
    save_line(x2,y2,z2, x0,y0,z0); 

    double xa,ya,za, xb,yb,zb, xc,yc,zc;

    xa = (x0 + x1)/2;
    ya = (y0 + y1)/2;
    za = (z0 + z1)/2;

    xb = (x1 + x2)/2;
    yb = (y1 + y2)/2;
    zb = (z1 + z2)/2;

    xc = (x2 + x0)/2;
    yc = (y2 + y0)/2;
    zc = (z2 + z0)/2;

    sier3d(x0,y0,z0, xa,ya,za, xc,yc,zc, depth-1);
    sier3d(x1,y1,z1, xb,yb,zb, xa,ya,za, depth-1);
    sier3d(x2,y2,z2, xc,yc,zc, xb,yb,zb, depth-1);    
}

void sier3d_extra(double x0, double y0, double z0, double x1, double y1, double z1, double x2, double y2, double z2, int depth)
{
    






    
}


int build_pyramid()
{
  int n,k ;
  double a,x[100],z[100],yv ;

  N = 0 ; // global
  
  n = 6 ;
  for (k = 0; k <= n ; k++) {
    a = k * 2*M_PI/n ; 
    x[k] = cos(a) ;
    z[k] = sin(a) ;
  }

  yv = -1 ;
  for (k = 0; k < n ; k++) {
//    save_line(0,2,0,  x[k],yv,z[k]) ;
//    save_line(x[k],yv,z[k],    x[k+1],yv,z[k+1]) ;
      sier3d(0,.5,0, x[k],yv,z[k], x[k+1],yv,z[k+1],4 );
  }  
  
}








int test_pyramid()
{
  G_init_graphics(Wsize,Wsize) ;
  G_rgb(0,0,0) ;
  G_clear() ;
  G_rgb(0,1,0) ;

  build_pyramid() ;
  project(3,45) ;
  draw() ;
  print_object() ;
  
  G_wait_key() ;
}




int test_pyramid_rotate()
{
  //  G_choose_repl_display() ; // not too bad as a repl movie
  G_init_graphics(Wsize,Wsize) ;

  build_pyramid() ;
  
  while (1) {
    G_rgb(0,0,0) ;
    G_clear() ;
    G_rgb(0,1,0) ;
    project(3,45) ;
    draw() ;
    rotate_x(2) ;  
    if (G_wait_key() == 'q') { break ; }
  }
  
}




int main()
{
  //test_pyramid() ;
  test_pyramid_rotate() ;
}
