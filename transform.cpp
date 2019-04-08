//#include<Windows.h>
#include<GL/glut.h>
#include<GL/gl.h>
#include<math.h>
#include<stdio.h>
#define SIN(x) sin(x * 3.141592653589/180)
#define COS(x) cos(x * 3.141592653589/180)

int tx=20;
int ty=80;
int sx=2;
int sy=2;
int q=180;
void display(float x[2][5]);
void translat(float m[2][5],int x,int y);
//void translat();
float m[2][5]={20,50,50,35,20,
            20,20,50,75,50};

void rotat(int r)
{
    float b[2][5];
    float p=m[0][0];
    float z=m[1][0];
    float a=SIN(r);
    float s=COS(r);

    for(int i=0;i<5;i++)
    {

        b[0][i]=m[0][i]-p;
        b[1][i]=m[1][i]-z;
        float c=b[0][i];
        float d=b[1][i];

        b[0][i]=(c*s) - (d*a);
        b[1][i]=(d*s) + (c*a);

        b[0][i]=b[0][i]+p;
        b[1][i]=b[1][i]+z;


   }
   display(b);
/*
for(int i=0;i<5;i++)
{
        m[0][i]=m[0][i]-25;
        m[1][i]=m[1][i]+25;
}
display();
*/
   //translat(m,-25,25);

   //display();

}

void translat(float m[2][5],int x,int y)
{
    for(int i=0;i<5;i++)
    {
        m[0][i]+=x;
        m[1][i]+=y;

    }

    display(m);
}
void scale(float m[2][5],int x,int y)
{
    float b[2][5];
int p=m[0][0];
int z=m[1][0];
        for(int i=0;i<5;i++)
        {
            b[0][i]=m[0][i]-p;
            b[1][i]=m[1][i]-z;

            b[0][i]*=x;
            b[1][i]*=y;

            b[0][i]=b[0][i]+p;
            b[1][i]=b[1][i]+z;

        }
        display(b);
        //for(int i=0;i<5;i++)
        //{
/*
            m[0][i]/=x;
            m[1][i]/=y;
            m[0][i]-=p;
            m[1][i]-=z;

        }
*/
}
void option()
{
      glClear(GL_COLOR_BUFFER_BIT);

    display(m);
   translat(m,-1*tx,-1*ty);

   scale(m,sx,sy);
rotat(q);
}

void display(float x[2][5])
{
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<5;i++)
    glVertex2i(x[0][i],x[1][i]);
    glEnd();

/*
    glBegin(GL_LINE_LOOP);
    glColor3f(1.0,1.0,0.0);
    glVertex2i(20,20);
    glVertex2i(50,20);
    glVertex2i(50,50);
    glVertex2i(35,75);
    glVertex2i(20,50);
    glEnd();
  */
    glFlush();

}

void init(void)
{
 glClearColor(0.0,0.0,0.0,1.0);
 glColor3f(1.0,1.0,1.0);
 glLineWidth(2);
 gluOrtho2D(-200,200,-200,200);
}

int main(int argc,char **argv)
{

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000,1000);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Transformation in 2D Object");

    glutDisplayFunc(option);
    init();
    glutMainLoop();
}
