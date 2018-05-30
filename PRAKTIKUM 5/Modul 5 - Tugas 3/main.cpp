#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <math.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    for (float i=0; i<3.14*2; i+=6.28/12 ){
        glColor3d(0,0,1);
        glPushMatrix();
        glTranslated(cos(i)*3.5, sin(i)*3.5, 0);
        glScaled(0.9, 0.9, 0);
        glRectf(-0.5, -0.5, 0.5, 0.5);
        glPopMatrix();
    }

    glBegin(GL_LINES);
    glColor3d(1,1,0);
    for (float i=0; i<3.14*2; i+=0.01){
        glVertex2f(cos(i)*3.5, sin(i)*3.5);
    }
    glEnd();

    glFlush ();
}
void myinit() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-5.0, 5.0, -5.0, 5.0);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(0.0,0.0,0.0,1.0);
}

int main(int argc, char* argv[]) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400,400);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Modul 5 - Tugas 3 - 160411100152");
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();
    return 0;
}
