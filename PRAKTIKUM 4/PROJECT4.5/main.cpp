#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <math.h>

void display()
{
glClear(GL_COLOR_BUFFER_BIT);

glColor3f(1.0, 1.0, 0.0);
// Gambar lingkaran
glBegin(GL_LINE_LOOP);
    for(float t=0.0; t<=6.28; t+=0.01)
    {
        glVertex2f(7*cos(t),7*sin(t));
    }
glEnd();
//Gambar sumbu koordinat

glBegin(GL_LINES);
glVertex3f(-10.0,0.0,0.0);
glVertex3f(10.0,0.0,0.0);
glVertex3f(0.0,-10.0,0.0);
glVertex3f(0.0,10.0,0.0);
glEnd();

glColor3f(0.0,0.0,0.5);
// Gambar kotak
int j=0;
for(float i=0;i<=6.28;i+=6.28/12){
if(j%2==0){
    glScaled(0.5,0.5,0);
    glTranslated(14*sin(i),14*cos(i),0);
    glRecti(-1,-1, 1, 1);
    glLoadIdentity();
}else{
    glTranslated(7*sin(i),7*cos(i),0);
    glRecti(-1,-1, 1, 1);
    glLoadIdentity();
}
j+=1;
}
glFlush();
}
void myinit()
{
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-10.0, 10.0, -10.0, 10.0);
glMatrixMode(GL_MODELVIEW);
glClearColor(1.0,1.0,1.0,1.0);
glColor3f(0.0,0.0,0.0);
}
int main(int argc, char* argv[])
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(400,400);
glutInitWindowPosition(100,100);
glutCreateWindow("Transform");
glutDisplayFunc(display);
myinit();
glutMainLoop();
return 0;
}
