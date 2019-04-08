//#include<windows.h>
#include<GL/glut.h>
#include<stdio.h>
#include<GL/gl.h>
#include<stdlib.h>
int coord[] = {
    100,10,
    20,250,
    100,370,
    30,470,
    430,50,
    500,420
    };

void Init(){
    glClearColor(1.0,1.0,1.0,0);
    glColor3f(0.0,.0,0.0);
    gluOrtho2D(-300 , 300 , -200 , 200);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_INT, 0, coord);
    glColor3f(1,0,0);
    glDrawArrays(GL_LINE_LOOP, 0, 6);
    glDisableClientState(GL_VERTEX_ARRAY);
    glFlush();
}
void reshape(int width, int height){
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0,width,0,height);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}


int main(int argc, char *argv[]){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(640,480);
    glutCreateWindow("Polygon_vertex_arrays");
    Init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
