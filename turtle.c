#include "FPToolkit.c"
#include <ctype.h>

char turtle_path[10000000];
char temp_turtle_path[10000000];
char temp[10000000];
char clear[100];


void move_turtle(double degrees_rotated, double turtle[], double rad)
{
    double op[2];
    double temp;
    double t = degrees_rotated * (M_PI/180);
    double c = cos(t) * rad;
    double s = sin(t) * rad;
    op[0] = turtle[0];
    op[1] = turtle[1];
    turtle[0] = turtle[0] + c;
    turtle[1] = turtle[1] + s;


    G_rgb (124.0/255,218.0/255,124.0/255);
//    G_fill_circle(turtle[0],turtle[1],10);
    G_line(op[0],op[1],turtle[0],turtle[1]);
    
    
}
void grammar(char turtle_path[],double d)
{
    if(d == 0)
    {
        return;
    }

    double len = strlen(turtle_path);
    
    int i = 0;
    while(i < len)
    {
        if(turtle_path[i] == 'x')
        {
            strcpy(temp, "B+[[x]-x]-B[-Bx]+x");
            strcat(temp_turtle_path,temp); 
        }
        else if(turtle_path[i] == 'B')
        {
            strcpy(temp, "BB");
            strcat(temp_turtle_path,temp);  
        }
        else if(turtle_path[i] == '+')
        {
            strcpy(temp, "+");
            strcat(temp_turtle_path,temp);
        }
        else if(turtle_path[i] == '-')
        {
            strcpy(temp, "-");
            strcat(temp_turtle_path,temp);  
        }
        else if(turtle_path[i] == '[')
        {
            strcpy(temp, "[");
            strcat(temp_turtle_path,temp);  
        }
        else if(turtle_path[i] == ']')
        {
            strcpy(temp, "]");
            strcat(temp_turtle_path,temp);  
        }
        
        ++i;
    }

    strcpy(turtle_path,temp_turtle_path);
    strcpy(temp_turtle_path,clear);
    grammar(turtle_path, d-1);
}

void background()
{
    double p1[2];
    double p2[2];

    p1[0] = 0.0;
    p1[1] = 0.0;
    p2[0] = 599.0;
    p2[1] = 0.0;

    int i = 0;
    while(i < 600)
    {
        p1[1] = p1[1] + 1;
        p2[1] = p2[1] + 1;
        G_rgb((222.0-i)/255,(63.0-i)/255,(6.0-i)/255);
        G_line(p1[0],p1[1],p2[0],p2[1]);
        ++i;
    }
}


int main()
{
    int    swidth, sheight ;

    swidth = 600;  sheight =600;
    G_init_graphics (swidth,sheight);

    double rad = 4;
    double degrees = 25;
    double d;

    printf("Type the directions for the turtle \n");

    scanf("%s", turtle_path);

    printf("Type the depth \n");

    scanf("%lf", &d);

    G_rgb (1, 1, 1);
    G_clear ();
    double degrees_rotated = 60;
    double turtle[2];
    double hold_posx[100000];
    double hold_posy[100000];
    double hold_angle[100000];


    G_rgb (0, 1, 0);

//    G_wait_click(turtle);
//    G_fill_circle(turtle[0],turtle[1],1);
    turtle[0] = 25.0;
    turtle[1] = 20.0;
    grammar(turtle_path,d);

    double moves = strlen(turtle_path);
    int i = 0;
    int j = 0;
    background();  
    while(i < moves)
    {
//        double r[2];
//        G_wait_click(r) ;
        double color = j;
        if(turtle_path[i] == 'B')
            move_turtle(degrees_rotated,turtle,rad);
        if(turtle_path[i] == '+')
            degrees_rotated = degrees_rotated + degrees;
        if(turtle_path[i] == '-')
            degrees_rotated = degrees_rotated - degrees;
        if(turtle_path[i] == '[')
        {
            hold_posx[j] = turtle[0];
            hold_posy[j] = turtle[1];
            hold_angle[j] = degrees_rotated;
            ++j;
        }
        if(turtle_path[i] == ']')
        {
            --j;
            turtle[0] = hold_posx[j];
            turtle[1] = hold_posy[j];
            degrees_rotated = hold_angle[j];
        }
        
//        printf("%c", turtle_path[i]);
        ++i;
        
    }
    
    

    double z[2];
    G_wait_click(z) ;

    G_save_to_bmp_file("branch.bmp") ;
}