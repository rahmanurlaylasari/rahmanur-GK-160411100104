#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
void display(){
glClear(GL_COLOR_BUFFER_BIT);
glLineWidth(3);
glBegin(GL_LINES);
glVertex2f (-15.0, 15.0);
glVertex2f (-15.0, -15.0);
glVertex2f (-15.0, -15.0);
glVertex2f (15.0, -15.0);
glVertex2f (15.0, -15.0);
glVertex2f (15.0, 15.0);
glVertex2f (15.0, 15.0);
glVertex2f (-15.0, 15.0);
glEnd();

glBegin(GL_LINES);
glVertex2f (-15.0, 5.0);
glVertex2f (15.0, 5.0);

glBegin(GL_LINES);
glVertex2f (-15.0, -5.0);
glVertex2f (15.0, -5.0);
glEnd();

glBegin(GL_LINES);
glVertex2f (-5.0, 15.0);
glVertex2f (-5.0, -15.0);

glBegin(GL_LINES);
glVertex2f (5.0, 15.0);
glVertex2f (5.0, -15.0);
glEnd();

glBegin(GL_LINES);
glColor3f (1.0, 1.0, 1.0);
glVertex2f (-3.0, 4.0);
glVertex2f (-3.0, -4.0);
glVertex2f (-3.0, -4.0);
glVertex2f (3.0, -4.0);
glVertex2f (3.0, -4.0);
glVertex2f (3.0, -2.5);
glVertex2f (3.0, -2.5);
glVertex2f (0.0, -2.5);
glVertex2f (0.0, -2.5);
glVertex2f (0.0, -1.0);
glVertex2f (0.0, -1.0);
glVertex2f (3.0, -1.0);
glVertex2f (3.0, -1.0);
glVertex2f (3.0, 1.0);
glVertex2f (3.0, 1.0);
glVertex2f (0.0, 1.0);
glVertex2f (0.0, 1.0);
glVertex2f (0.0, 2.5);
glVertex2f (0.0, 2.5);
glVertex2f (3.0, 2.5);
glVertex2f (3.0, 2.5);
glVertex2f (3.0, 4.0);
glVertex2f (3.0, 4.0);
glVertex2f (-3.0, 4.0);
glEnd();

glBegin(GL_LINES);
glColor3f (0.0, 1.0, 1.0);
glVertex2f (7.0, 14.0);
glVertex2f (12.0, 14.0);
glVertex2f (12.0, 14.0);
glVertex2f (12.0, 11.0);
glVertex2f (12.0, 11.0);
glVertex2f (8.0, 11.0);
glVertex2f (8.0, 11.0);
glVertex2f (8.0, 8.0);
glVertex2f (8.0, 8.0);
glVertex2f (12.0, 8.0);
glVertex2f (12.0, 8.0);
glVertex2f (12.0, 6.5);
glVertex2f (12.0, 6.5);
glVertex2f (7.0, 6.5);
glVertex2f (7.0, 6.5);
glVertex2f (7.0, 12.0);
glVertex2f (7.0, 12.0);
glVertex2f (11.0, 12.0);
glVertex2f (11.0, 12.0);
glVertex2f (11.0, 12.5);
glVertex2f (11.0, 12.5);
glVertex2f (7.0, 12.5);
glVertex2f (7.0, 12.5);
glVertex2f (7.0, 14.0);
glVertex2f (7.0, 14.0);

glEnd();
glFlush();
}
void myinit(){
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-20.0,20.0,-20.0,20.0);
glMatrixMode(GL_MODELVIEW);
glClearColor(0.0,0.0,0.0,0.0);
glColor3f (0.0, 0.0, 1.0);
}
int main(int argc, char* argv[]){
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(500,500);
//glutInitWindowPosition(100,100);
glutCreateWindow("Obyek Primitif");
glutDisplayFunc(display);
myinit();
glutMainLoop();
return 0;
}
