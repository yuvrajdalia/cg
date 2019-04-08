//#include <windows.h>
#include <iostream>
#include <math.h>
#include <GL/glut.h>

using namespace std;

int a,b,xc,yc;
float r,g,bl;

void init()
{
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-320,320,-240,240);
}

void plot (GLint x, GLint y, GLfloat r, GLfloat g, GLfloat b)
{
    glColor3f(r,g,b);
    glPointSize(1.0);
    glBegin (GL_POINTS);
    glVertex2i (x,y);
    glEnd();
}

void symmetricPixels (int x, int y, int xc, int yc, float r, float g, float b)
{
    plot (xc + x, yc + y, r,g,b);
    plot (xc - x, yc + y,r,g,b);
    plot (xc + x, yc - y,r,g,b);
    plot (xc - x, yc - y,r,g,b);
}

void Ellipse ()
{
    int aSq,bSq,twoASq,twoBSq,d,dx,dy,x,y;
    aSq = a*a;
    bSq = b*b;
    twoASq = 2*aSq;
    twoBSq = 2*bSq;
    d = bSq - b*aSq + aSq/4;
    dx = 0;
    dy = twoASq*b;
    x = 0;
    y = b;
    symmetricPixels(x,y,xc,yc,r,g,bl);
    while (dx < dy)
    {
        x++;
        dx += twoBSq;
        if (d >= 0)
        {
            y--;
            dy -= twoASq;
        }
        if (d < 0)
            d += bSq + dx;
        else
            d += bSq + dx - dy;
        symmetricPixels (x,y,xc,yc,r,g,bl);
    }
    d = (int)(bSq*(x+0.5)*(x+0.5) + aSq*(y-1)*(y-1) -aSq*bSq);

    while (y > 0)
    {
        y--;
        dy -= twoASq;
        if (d <= 0)
        {
            x++;
            dx += twoBSq;
        }
        if (d > 0)
            d += aSq - dy;
        else
            d += aSq -dy +dx;
        symmetricPixels(x,y,xc,yc,r,g,bl);
    }
    glFlush();
}

void launcher(int a, int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(200,200);
    glutCreateWindow("Many Amaze Very GL WOW");
    init();
    glutMainLoop();
}

int main(int argc, char** argv)
{
    cout<<"Enter the center of the ellipse: ";
    cin>>xc>>yc;
    cout<<"Enter the major axis and minor axis paramemetrs: ";
    cin>>a>>b;
    r=1;
    g=0;
    bl=0;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(200,200);
    glutCreateWindow("Many Amaze Very GL WOW");
    init();
    glClear(GL_COLOR_BUFFER_BIT);
    glutDisplayFunc(Ellipse);
    glutMainLoop();
    return 0;
}
