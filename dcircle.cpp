//#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
using namespace std;

int pntX1, pntY1, r;

void plot(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x+pntX1, y+pntY1);
	glEnd();
}


void myInit (void)
{
	glClearColor(1.0, 1.0, 0.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-640.0, 640.0, -480.0, 480.0);
}


void midPointCircleAlgo()
{
int x=0;
int y=r;
int h=1-r;
int de=3;
int dse=-2*r+5;
//print(h,x1,y1)
while (x<y)
    {if(h<0)
        h+=de;
    else
        {h+=dse;
        dse+=2;
        y-=1;}
    x+=1;
    de+=2;
    dse+=2;
		plot(x, y);
		plot(x, -y);
		plot(-x, y);
		plot(-x, -y);
		plot(y, x);
		plot(-y, x);
		plot(y, -x);
		plot(-y, -x);
	}

}

void myDisplay(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (1.0, 0.0, 0.0);
	glPointSize(1.0);

	midPointCircleAlgo();

	glFlush ();
}

int main(int argc, char** argv)
{
	cout << "Enter the coordinates of the center:\n\n" << endl;

	cout << "enter x co ordinate of center  : "; cin >> pntX1;
	cout << "\enter y coordinate of center : "; cin >> pntY1;
	cout << "\nEnter radius : "; cin >> r;


	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (640, 480);
	glutInitWindowPosition (100, 150);
	glutCreateWindow ("Line Drawing Alogrithms");
	glutDisplayFunc(myDisplay);
	myInit ();
	glutMainLoop();

}
