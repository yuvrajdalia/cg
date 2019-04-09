//#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>

int x1, y1, x2, y2;

void myInit() {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.4, 0.8, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-500, 500, -500, 500);
}

void draw_pixel(int x, int y) {
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void draw_line(int x1, int x2, int y1, int y2) {
int incry;
int slopegt1=0;
int dy=y2-y1;
int dx=x2-x1;
int d0=2*dy-dx;
int de=2*dy;
int dne=2*dy-2*dx;
if(dy>dx)
	{
		int temp=x1;
    	x1=y1;
    	y1=temp;

    	temp=x2;
    	x2=y2;
    	y2=temp;
    	
    	temp=dx;
    	dx=dy;
    	dy=temp;    	
		slopegt1=1;
	}
	if(x1>x2)
	{    	
		int temp=x1;
    	x1=x2;
    	x2=temp;
    	
    	temp=y1;
    	y1=y2;
    	y2=temp;		
	}
	if(y1>y2)
		incry=-1;
	else
		incry=1;
while (x1<x2){
    if(d0<=0)
        d0+=de;
    else
        {d0+=dne;
        y1+=incry;}
    x1+=1;
    draw_pixel(x1,y1);
}
}

void myDisplay() {
	draw_line(x1, x2, y1, y2);
	glFlush();

}

int main(int argc, char **argv) {

	printf( "Enter (x1, y1, x2, y2)\n");
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Bresenham's Line Drawing");
	myInit();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
}
