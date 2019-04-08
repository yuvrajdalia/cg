#include<algorithm>
using namespace std;
#include<stdio.h>
//#include<Windows.h>
#include<GL/glut.h>
#include<GL/gl.h>
int x1,x2,y1,y2;
int xmin,xmax,ymin,ymax;
void boun()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);
     glBegin(GL_LINE_LOOP);
    glVertex2i(xmin,ymin);
    glVertex2i(xmin,ymax);
    glVertex2i(xmax,ymax);
    glVertex2i(xmax,ymin);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(x1,y1);
    glVertex2i(x2,y2);
    glEnd();

    glFlush();

}
void lian()
{
    float u1=0,u2=1;
    int dx=(x2-x1);
    int dy=(y2-y1);
    double p[4],q[4];
    p[0]=-dx;
    q[0]=x1-xmin;
    p[1]=dx;
    q[1]=xmax-x1;
    p[2]=-dy;
    q[2]=y1-ymin;
    p[3]=dy;
    q[3]=ymax-y1;

    for(int i=0;i<4;i++)
    {

        if(p[i]==0)
        {
           if(q[i]<0)
                boun();
        }
        else if(p[i]<0)
        {
            float t=q[i]/p[i];
            if(t>u1 && t<u2)
                u1=t;

        }
        else if(p[i]>0)
        {
            float t=q[i]/p[i];
            if(t>u1 && t<u2)
                u2=t;

        }
    }
    if(u2>u1)
    {
        x1=x1+u1*(x2-x1);
        y1=y1+u1*(y2-y1);
        x2=x1+u2*(x2-x1);
        y2=y1+u2*(y2-y1);

        boun();

    }
}



void display()
{

    glClear(GL_COLOR_BUFFER_BIT);
     xmin=-200;
     xmax=200;
    ymin=-200;
    ymax=200;

     x1=-250;
     y1=-200;
     x2=20;
     y2=250;

  boun();

    glFlush();

}

void mykey(unsigned char key,int x,int y)
{

    if(key='c')
        lian();

}








int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(0,0);

    glutCreateWindow("Clip");

glClearColor(1.0,1.0,0.0,1.0);
    glOrtho(-500,500,-500,500,-1,1);
    glutDisplayFunc(display);
    glutKeyboardFunc(mykey);
    glutMainLoop();
    return 0;

}

