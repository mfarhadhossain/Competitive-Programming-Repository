FIRST LAB(LINE):::::

#include<windows.h>
#include<gl/glut.h>

void draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0);

    glBegin(GL_LINES);
    glColor3f(1.0,1.0,0.0);
    glVertex3f(-6, 4, 0.0);
    glVertex3f(-9, 6, 0.0);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3f(1.0,1.0,0.0);
    glVertex3f(-6,6,0);
    glVertex3f(-4,6,0);
    glVertex3f(-4,4,0);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(1.0,1.0,0.0);
    glVertex3f(-3,6,0);
    glVertex3f(-3,4,0);
    glVertex3f(-1,4,0);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3f(1.0,1.0,0.0);
    glVertex3f(1.5,6,0);
    glVertex3f(3,3,0);
    glVertex3f(0,3,0);
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(1.0,1.0,0.0);
    glVertex3f(4,5,0);
    glVertex3f(7,3,0);
    glVertex3f(4,3,0);
    glVertex3f(7,5,0);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0,1.0,0.0);
    glVertex3f(-8,1,0);
    glVertex3f(-5,-2,0);
    glVertex3f(-8,-2,0);
    glVertex3f(-5,1,0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,0.0);
    glVertex3f(0,0,0);
    glVertex3f(-1,1,0);
    glVertex3f(-3,1,0);
    glVertex3f(0,-2,0);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3f(1.0,1.0,0.0);
    glVertex3f(4,0,0);
    glVertex3f(3,1,0);
    glVertex3f(4,-2,0);
    glVertex3f(1,1,0);
    glVertex3f(2,-2,0);
    glVertex3f(1,-1,0);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,0.0);
    glVertex3f(8,0,0);
    glVertex3f(7,1,0);
    glVertex3f(6,1,0);
    glVertex3f(5,0,0);
    glVertex3f(5,-1,0);
    glVertex3f(6,-2,0);
    glVertex3f(7,-2,0);
    glVertex3f(8,-1,0);
    glEnd();

    glFlush();
}
void initialize()
{
    glClearColor(0.0,0.0,0.0,0.0);///color
    glMatrixMode(GL_PROJECTION);///matrix display
    glLoadIdentity();///for checking
    glOrtho(-10,10,-8,8,-1,1);///
}

int main(int Argc, char **Argv)
{
    glutInit(&Argc, Argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    ///single, double buffer, why use buffer, use of single double buffer
    glutInitWindowSize(850,900);
    glutInitWindowPosition(50,50);
    glutCreateWindow("MY WINDOW");
    ///glutDisplayFunc(initialize);
    initialize();
    glutDisplayFunc(draw);
    /// glutDisplayFunc(bresenhamLine(1,2,7,8));
    glutMainLoop();///event gula show kore

    return 0;
}



SECOND LAB(BRESENHAM LINE):::

#include<windows.h>
#include<GL/glut.h>
#include<iostream>
using namespace std;
int x1,x2,y1,y2;

void put_pixel(int x, int y)
{
    glPointSize(7);
    glBegin(GL_POINTS);
    glVertex2f(x,y);

    glEnd();
}


void bresenhamLine(){
    int x,y,dx,dy,m;
    int d,dd;

    x=x1;
    y=y1;

    dx=x2-x1;
    dy=y2-y1;
    m=dy/dx;

    d=2*dx-dy;
     dd=2*dy-dx;



    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,0);

     if(m<1)
     {

    while(y<=y2)
    {
        put_pixel(x,y);
        y++;
        if(d<0)
        {
            d=d+2*dx;
        }
        else
        {
            d=d+2*dx-2*dy;
            x++;
        }
    }
     }
    else
    {
    while(x<=x2)
    {
        put_pixel(x,y);
        x++;
        if(dd<0)
        {
            dd=dd+2*dy;
        }
        else
        {
            dd=dd+2*dy-2*dx;
            y++;
        }
    }

     }


    glFlush();
}


void initialize()
{
    glClearColor(1,0,1,1);///color
    glMatrixMode(GL_PROJECTION);///matrix display
    glLoadIdentity();///for checking
    glOrtho(-100,100,-100,100,-1,1);///
}

int main(int Argc, char **Argv){
    glutInit(&Argc, Argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    ///single, double buffer, why use buffer, use of single double buffer
    glutInitWindowSize(50,800);
    glutInitWindowPosition(50,50);
    glutCreateWindow("Soliman 1989");
    ///glutDisplayFunc(initialize);
    cout<<"Enter Values:\n";
    cout<<"x1: ";
    cin>>x1;
    cout<<"y1: ";
    cin>>y1;
    cout<<"x2: ";
    cin>>x2;
    cout<<"y2: ";
    cin>>y2;
    initialize();
    glutDisplayFunc(bresenhamLine);
    /// glutDisplayFunc(bresenhamLine(1,2,7,8));
    glutMainLoop();///event gula show kore

    return 0;
}



DIFFERNT FORMULA:::::
#include<windows.h>
#include<gl/glut.h>
#include<iostream>

using namespace std;

int X1,X2,Y1,Y2,dX,dY,t1,t2;
void put_pixel(GLint x,GLint y)
{
    glPointSize(3);
    glBegin(GL_POINTS);
    glVertex2f(x,y);
    glEnd();
}

void Line1()
{

    int x=X1;
    int y=Y1;
    int D;
    D=2*dY-dX;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,1.0);
    put_pixel(x,y);

    while(x<=X2)
    {
        x++;
        if(D<0)
        {
            D=D+2*dY;
        }
        else
        {
            D=D+2*dY-2*dX;
            y++;
        }
           if(t1<0&&t2<0)
        {
            put_pixel((x-2*(x-X1)),(y-2*(y-Y1)));
        }
        else if(t2<0)
        {
            put_pixel(x,(y-2*(y-Y1)));
        }
        else if(t1<0)
        {
            put_pixel((x-2*(x-X1)),y);
        }
        else
        {
            put_pixel(x,y);
        }

    }
    glFlush();
}
void Line2()
{
    int x=X1;
    int y=Y1;
    int D=2*dX-dY;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,0.0);
    put_pixel(x,y);

    while(y<=Y2)
    {


        if(D<0)
        {
           D=D+2*dX;

        }

        else
        {
            D=D+2*dX-2*dY;
            x++;
        }
          y++;
          if(t1<0&&t2<0)
        {
            put_pixel((x-2*(x-X1)),(y-2*(y-Y1)));
        }
        else if(t2<0)
        {
            put_pixel(x,(y-2*(y-Y1)));
        }
        else if(t1<0)
        {
            put_pixel((x-2*(x-X1)),y);
        }
        else
        {
            put_pixel(x,y);
        }

    }
    glFlush();
}

void initialize()
{
    glClearColor(0.5,0.8,0.7,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-250,250,-250,250,-1,1);
}

int main(int Argc, char **Argv)
{
    cout<<"Enter the co-ordinates of two points: "<<endl;
    cout<<"Enter X1,Y1: ";
    cin>>X1>>Y1;
    cout<<"Enter X2,Y2: ";
    cin>>X2>>Y2;
    dX=X2-X1;
    dY=Y2-Y1;
    if(dX<0)
    {
        t1=dX;
        dX=dX*(-1);
        X2=X1+dX;
    }
    if(dY<0)
    {
        t2=dY;
        dY=dY*(-1);
        Y2=Y1+dY;
    }
    glutInit(&Argc, Argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(800,800);
    glutInitWindowPosition(50,50);
    glutCreateWindow("Bresenham Line");
    initialize();
    if(dX==0)
    {
        glutDisplayFunc(Line2);
    }
    else if((dY/dX)<1)
    {
        glutDisplayFunc(Line1);
    }
    else
    {
        glutDisplayFunc(Line2);
    }
    glutMainLoop();
    return 0;
}



THIRD LAB(BRESENHAM CIRCE)::::::
#include<windows.h>
#include<gl/glut.h>

void putpixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2f(x,y);
    glEnd();
}


void midpointcircle(int r)
{
    int x,y,p;
    x=0;
    y=r;
    p=1-r;
    while(x<=y)
    {
        putpixel(x,y);
        putpixel(x,-y);
        putpixel(-x,y);
        putpixel(-x,-y);
        putpixel(y,x);

        putpixel(-y,x);
        putpixel(y,-x);
        putpixel(-y,-x);

        if(p<0)
           {
               x++;
               p=p+2*x+1;
           }
            ///p=p+4*x+6 bresenham circle
        else
        {
            x++;
            p=p+2*(x-y)+1;
            ///p=p+*(x-y)+10 bresenham circle
            y--;
        }

    }
}

void bresenhamcircle(int r)
{
    int x,y,p;
    x=0;
    y=r;
    p=3-2*r;
    while(x<=y)
    {
        putpixel(x,y);
        putpixel(x,-y);
        putpixel(-x,y);
        putpixel(-x,-y);
        putpixel(y,x);
        putpixel(-y,x);
        putpixel(y,-x);
        putpixel(-y,-x);
        if(p<0)
           {
               p=p+4*x+6;
           }
        else
        {

            p=p+4*(x-y)+10;
            y--;
        }
        x++;
    }
}

void draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
      glColor3f(0,0,0);
   /// midpointcircle(200);
    bresenhamcircle(200);


    glFlush();
}

void initialize()
{
    glClearColor(1.0,0.0,0.0,0.0);///color
    glMatrixMode(GL_PROJECTION);///matrix display
    glLoadIdentity();///for checking
    glOrtho(-500,500,-500,500,-1,1);///
}

int main(int Argc, char **Argv)
{
    glutInit(&Argc, Argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    ///single, double buffer, why use buffer, use of single double buffer
    glutInitWindowSize(850,900);
    glutInitWindowPosition(50,50);
    glutCreateWindow("MY WINDOW");
    ///glutDisplayFunc(initialize);
    initialize();


    glutDisplayFunc(draw);


    ///glutDisplayFunc(bresenhamLine(1,2,6,8));
    glutMainLoop();///event gula show kore

    return 0;
}







FOURTH LAB(ELIPSE)::::::::


#include<windows.h>
#include<gl/glut.h>
void put_pixel(int x,int y)
{
    glBegin(GL_POINTS);
    glVertex2f(x,y);
    glEnd();
}
void Ellipse()
{
    int a=30,b=25;
    int aa=a*a;
    int bb=b*b;
    int aa2=aa*2;
    int bb2=bb*2;
    int x=0,y=b;
    int fx=0;
    int fy=aa2*b;
    int p=bb-aa*b+aa/4;
    put_pixel(x,y);
        put_pixel(-x,y);
        put_pixel(x,-y);
        put_pixel(-x,-y);
    while(fx<fy)
    {
        x++;
        fx=fx+bb2;
        if(p<0)
        {
            p=p+fx+bb;
        }
        else{
            y--;
            fy=fy-aa2;
            p=p+fx+bb-fy;
        }
        put_pixel(x,y);
        put_pixel(-x,y);
        put_pixel(x,-y);
        put_pixel(-x,-y);

        p=bb*(x+0.5)*(x+0.5)+aa*(y-1)*(y-1)-aa*bb;
    }
    while(y>0)
    {
        y--;
        fy=fy-aa2;
        if(p>=0)
        {
            p=p-fy+aa;
        }
        else{
            x++;
            fx=fx+bb2;
            p=p-fy+aa+fx;
        }
     put_pixel(x,y);
        put_pixel(-x,y);
        put_pixel(x,-y);
        put_pixel(-x,-y);
        }
        glFlush();
}
void initialize()
{
glClearColor(1,0.0,1,1);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-100,80,-100,80,-1,1);
}

int main(int Argc,char **Argv)
{
glutInit(&Argc,Argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(850,800);
glutInitWindowPosition(50,50);
glutCreateWindow("My Window");
initialize();
glutDisplayFunc(Ellipse);
glutMainLoop();
return 0;
}




FIFTH LAB(TRANSFORMATION):::::
5.1- Translation:::
#include<windows.h>
#include<GL/glut.h>
#include<iostream>
using namespace std;
int X[100],Y[100],n,tx,ty;

void PolygonDraw()
{

    glBegin(GL_POLYGON);
    glColor3f(1,0,0);

    for(int i=0;i<n;i++){
      glVertex2i(X[i],Y[i]);
    }

        glEnd();
        glFlush();

}

void polygontrans()
{


    glBegin(GL_POLYGON);
    glColor3f(10,0,0);
    for(int i=0;i<n;i++)
        glVertex2i(X[i]+tx,Y[i]+ty);
        glEnd();
        glFlush();

}
void mydisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,0);
    PolygonDraw();
    polygontrans();
    glFlush();
}


void initialize()
{
    glClearColor(1,0,1,1);///color
    glMatrixMode(GL_PROJECTION);///matrix display
    glLoadIdentity();///for checking
    glOrtho(-100,100,-100,100,-1,1);///
}

int main(int Argc, char **Argv){
    glutInit(&Argc, Argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    ///single, double buffer, why use buffer, use of single double buffer
    glutInitWindowSize(500,800);
    glutInitWindowPosition(50,50);
    glutCreateWindow("");
    ///glutDisplayFunc(initialize);
    cout<<"Enter value of edges:\n";
    cin>>n;


     for(int i=0;i<n;i++){
    cout<<"x and y: ";
     cin>>X[i]>>Y[i];

     cin>>Y[i];
    }
    cout<< "Enter translation factor for x-axis: " ;
    cin>> tx;
    cout<< "Enter translation factor for y-axis: " ;
    cin>>ty;


    initialize();
    glutDisplayFunc(mydisplay);
    /// glutDisplayFunc(bresenhamLine(1,2,7,8));
    glutMainLoop();///event gula show kore

    return 0;
}


5.2:: SCAlling::

#include<windows.h>
#include<GL/glut.h>
#include<iostream>
using namespace std;
int X[100],Y[100],n,Sx,Sy;

void PolygonDraw()
{

    glBegin(GL_POLYGON);
    glColor3f(1,0,0);

    for(int i=0;i<n;i++){
      glVertex2i(X[i],Y[i]);
    }

        glEnd();
        glFlush();

}

void polygontrans()
{


    glBegin(GL_POLYGON);
    glColor3f(10,0,0);
    for(int i=0;i<n;i++)
        glVertex2i(X[i]*Sx,Y[i]*Sy);
        glEnd();
        glFlush();

}
void mydisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,0);
    PolygonDraw();
    polygontrans();
    glFlush();
}


void initialize()
{
    glClearColor(1,0,1,1);///color
    glMatrixMode(GL_PROJECTION);///matrix display
    glLoadIdentity();///for checking
    glOrtho(-200,200,-200,200,-1,1);///
}

int main(int Argc, char **Argv){
    glutInit(&Argc, Argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    ///single, double buffer, why use buffer, use of single double buffer
    glutInitWindowSize(500,800);
    glutInitWindowPosition(50,50);
    glutCreateWindow("");
    ///glutDisplayFunc(initialize);
    cout<<"Enter value of edges:\n";
    cin>>n;


     for(int i=0;i<n;i++){
    cout<<"x and y: ";
     cin>>X[i];

     cin>>Y[i];
    }
    cout<< "Enter translation factor for x-axis: " ;
    cin>> Sx;
    cout<< "Enter translation factor for y-axis: " ;
    cin>>Sy;


    initialize();
    glutDisplayFunc(mydisplay);
    /// glutDisplayFunc(bresenhamLine(1,2,7,8));
    glutMainLoop();///event gula show kore

    return 0;
}

5.3-Counter clock:::
#include<windows.h>
#include<GL/glut.h>
#include<iostream>
#include<math.h>
using namespace std;
int X[100],Y[100],n,tt,angle;

void PolygonDraw()
{

    glBegin(GL_POLYGON);
    glColor3f(1,0,0);

    for(int i=0;i<n;i++){
      glVertex2i(X[i],Y[i]);
    }

        glEnd();
        glFlush();

}

void polygontrans()
{


    glBegin(GL_POLYGON);
    glColor3f(10,0,0);
    for(int i=0;i<n;i++)
    {


        glVertex2i((X[i]*cos(angle)-Y[i]*cos(angle)),(X[i]*sin(angle)+Y[i]*cos(angle)));
    }
        glEnd();
        glFlush();

}
void mydisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,0);
    PolygonDraw();
    polygontrans();
    glFlush();
}


void initialize()
{
    glClearColor(1,0,1,1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-200,200,-200,200,-1,1);
}

int main(int Argc, char **Argv){
    glutInit(&Argc, Argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

    glutInitWindowSize(500,800);
    glutInitWindowPosition(50,50);
    glutCreateWindow("");

    cout<<"Enter value of edges:\n";
    cin>>n;


     for(int i=0;i<n;i++){
    cout<<"x and y: ";
     cin>>X[i];

     cin>>Y[i];
    }
    cout<<"theta: ";
    cin>>tt;
    angle=(tt*3.1416)/180;

    initialize();
    glutDisplayFunc(mydisplay);

    glutMainLoop();

    return 0;
}

5.4-Clock Wise:::
#include<windows.h>
#include<GL/glut.h>
#include<iostream>
#include<math.h>
using namespace std;
int X[100],Y[100],n,tt,angle;

void PolygonDraw()
{

    glBegin(GL_POLYGON);
    glColor3f(1,0,0);

    for(int i=0;i<n;i++){
      glVertex2i(X[i],Y[i]);
    }

        glEnd();
        glFlush();

}

void polygontrans()
{


    glBegin(GL_POLYGON);
    glColor3f(10,0,0);
    for(int i=0;i<n;i++)
    {


        glVertex2i((X[i]*cos(angle)+Y[i]*cos(angle)),(Y[i]*cos(angle)-X[i]*sin(angle)));
    }
        glEnd();
        glFlush();

}
void mydisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,0);
    PolygonDraw();
    polygontrans();
    glFlush();
}


void initialize()
{
    glClearColor(1,0,1,1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-200,200,-200,200,-1,1);
}

int main(int Argc, char **Argv){
    glutInit(&Argc, Argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

    glutInitWindowSize(500,800);
    glutInitWindowPosition(50,50);
    glutCreateWindow("");

    cout<<"Enter value of edges:\n";
    cin>>n;


     for(int i=0;i<n;i++){
    cout<<"x and y: ";
     cin>>X[i];

     cin>>Y[i];
    }
    cout<<"theta: ";
    cin>>tt;
    angle=(tt*3.1416)/180;

    initialize();
    glutDisplayFunc(mydisplay);

    glutMainLoop();

    return 0;
}







