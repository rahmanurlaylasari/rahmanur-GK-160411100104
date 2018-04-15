#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <math.h>


#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <math.h>

void garisKordinat() {
    glBegin(GL_LINES);
        glVertex3f(-10.0,0.0,0.0);
        glVertex3f(10.0,0.0,0.0);
        glVertex3f(0.0,-10.0,0.0);
        glVertex3f(0.0,10.0,0.0);
    glEnd();
}
putik(){
    // Gambar putik
    glColor3f(1.0,0.5,1.0);
    glBegin(GL_POLYGON);
    for(float t=0.0; t<=6.28; t+=0.01) {
        glVertex2f(cos(t),sin(t));
    }
    glEnd();
}

void kelopak(){
// Gambar kelopak Bagian Kiri
    glTranslated(0,4.2+(0.2),0);

    glBegin(GL_POLYGON);
    glColor3f(1.0,0.5,1.0);
    glVertex2f(0,-3.2);
    for(float t=0.14; t<=2.7; t+=0.01)
    {
        if ( t <=2 ){
                glColor3f(1.0,0.5,1.0);
            } else{
                glColor3f(1.0,0.7,1.0);
            }
        glVertex2f(1.8*sin(t),-3*cos(t));
    }
    glColor3f(1.0,0.7,1.0);
    glVertex2f(0,1.5);
    for(float t=0.44; t<=3.0; t+=0.01)
    {
        if ( t <=1.34 ){
                glColor3f(1.0,0.7,1.0);
            } else {
                glColor3f(1.0,0.5,1.0);
            }
        glVertex2f(1.8*sin(t),3*cos(t));
    }
    glEnd();

    // Mirror ke Kanan
    glScaled(-1,1,0);
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.5,1.0);
    glVertex2f(0,-3.2);
    for(float t=0.14; t<=2.7; t+=0.01)
    {
        if ( t <=2 ){
                glColor3f(1.0,0.5,1.0);
            } else{
                glColor3f(1.0,0.7,1.0);
            }
        glVertex2f(1.8*sin(t),-3*cos(t));
    }
    glColor3f(1.0,0.7,1.0);
    glVertex2f(0,1.5);
    for(float t=0.44; t<=3.0; t+=0.01)
    {
        if ( t <=1.34 ){
                glColor3f(1.0,0.7,1.0);
            } else {
                glColor3f(1.0,0.5,1.0);
            }
        glVertex2f(1.8*sin(t),3*cos(t));
    }
    glEnd();
    glScaled(-1,1,0);
}



void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    putik();
    int x=5;
    for(float i=0;i<x;i++){
        glRotated((360/x)*i,0,0,1);
        kelopak();
        glLoadIdentity();
    }
    glFlush();
}
void myinit() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10.0, 10.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(0.0,0.0,0.0,1.0);
    glColor3f(0.0,0.0,0.0);
}
int main(int argc, char* argv[]) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400,400);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Sakura KW");
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();
    return 0;
}
