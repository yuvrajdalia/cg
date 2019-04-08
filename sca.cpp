#include<GL/glut.h>
#include<GL/gl.h>
#include<stdio.h>
class po
{
public:
    int t[500];
    int k=0;
    po(){
        for(int i=0;i<500;i++)
            t[i]=0;
    }

};
void sor(po* le)
{
    int temp;
    for(int i=0;i<500;i++)
    {
        for(int j=0;j<le[i].k;j++)
        {
            for(int m=j;m<le[i].k;m++)
            {
               if(le[i].t[m]<le[i].t[j])
                    {
                        temp=le[i].t[m];
                        le[i].t[m]=le[i].t[j];
                        le[i].t[j]=temp;
                    }
            }

        }
    }

}
int x[10];
int y[10];

void fil(int lx,int rx,int i)
{
    
    int s=lx;
    int e=rx;
    if(lx>rx)
    {
        s=rx;
        e=lx;
    }

    glBegin(GL_POINTS);
    glColor3f(0.0,1.0,0.0);
for(int j=s;j<e;j++)
{
   
    glVertex2i(j,i);
}

glEnd();
glFlush();
}
void scan(int xl,int yl,int xr,int yr,po* le,int i)
{
    int m;

   if(xl==xr)
    m=100000;
   else if(yl==yr)
    m=0;
   else{
    m=(yr-yl)/(xr-xl);
   }
   int mx;
   int ys=yl;
   int ye=yr;
   if(yl>yr)
   {
   ys=yr;
   ye=yl;
   }


for(int i=ys;i<ye;i++)
{

if(m!=0)
    mx=xl+(i-yl)/m;
else
    mx=xl;

    if(m!=0)
    {
    int a=le[i].k;
    le[i].t[a]=mx;
    le[i].k=le[i].k+1;
    }
    else{

    int a=le[i].k;
    le[i].t[a]=xl;
    le[i].k=le[i].k+1;
    a=le[i].k;
    le[i].t[a]=xr;
    le[i].k=le[i].k+1;


    }


}
int n=i+2;
if(i=6)
n=0;


float m1=y[i+1]-y[i]/(x[i+1]-x[i]);
float m2=y[n]-y[i+1]/(x[n]-x[i+1]);
int z=0;
if(m1>=0 && m2<0)
    z=1;
else if(m1<0 && m2>0)
z=1;

if(z=1)
{
int a;
    a=le[ye].k;
    le[ye].t[a]=xr;
    le[ye].k=le[ye].k+1;

    a=le[ye].k;
    le[ye].t[a]=xr;
    le[ye].k=le[ye].k+1;


}
else{
int a;
    a=le[ye].k;
    le[ye].t[a]=xr;
    le[ye].k=le[ye].k+1;

}
}

void display()
{
        po le[500];

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,0.0);
    glPointSize(1);
   x[0]=100;y[0]=100;
   x[1]=150;y[1]=300;
   x[2]=200;y[2]=200;
   x[3]=200;y[3]=300;
   x[4]=250;y[4]=250;
   x[5]=350;y[5]=150;
   x[6]=350;y[6]=300;
   x[7]=400;y[7]=100;


    glBegin(GL_LINE_LOOP);
    glVertex2i(x[0],y[0]);
    glVertex2i(x[1],y[1]);
    glVertex2i(x[2],y[2]);
    glVertex2i(x[3],y[3]);
    glVertex2i(x[4],y[4]);
   glVertex2i(x[5],y[5]);
    glVertex2i(x[6],y[6]);
    glVertex2i(x[7],y[7]);
    glEnd();
    glBegin(GL_LINE_LOOP);
     glColor3i(1,0,0);
    glVertex2i(0,0);
    glVertex2i(0,500);
    glVertex2i(500,500);
    glVertex2i(500,0);
    glEnd();

    glFlush();

    scan(x[0],y[0],x[1],y[1],le,0);
    scan(x[1],y[1],x[2],y[2],le,1);
    scan(x[2],y[2],x[3],y[3],le,2);
    scan(x[3],y[3],x[4],y[4],le,3);
    scan(x[4],y[4],x[5],y[5],le,4);
    scan(x[5],y[5],x[6],y[6],le,5);
    scan(x[6],y[6],x[7],y[7],le,6);


sor(le);
        for(int i=0;i<500;i++)
    {
        for(int j=0;j<le[i].k;j=j+2)
        {
           fil(le[i].t[j],le[i].t[j+1],i);
        }
        }


    glFlush();

}

int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(10,10);
    glutInitWindowSize(640,480);
    glutCreateWindow("Scanfill");

    glClearColor(1.0,0.0,1.0,1.0);
    glOrtho(-300,800,-300,800,-1,1);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;

}
