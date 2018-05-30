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

    int hitung = 0;
    for (float i=0; i<3.14*2; i+=(3.14*2)/12) {
        glColor3d(0,0,1);
        glPushMatrix();
        glRotated(i*360/6.28, 0, 0, 1);
        if (hitung%2 == 0) {
            glScaled(1, 1, 1);
            glTranslated(0, 3.5, 0);
        } else {
            glScaled(0.5, 0.5, 1);
            glTranslated(0, 7, 0);
        }
        glRectf(-0.5,-0.5,0.5,0.5);
        glPopMatrix();
        hitung++;
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
    glColor3d(1,1,1);
}
int main(int argc, char* argv[]) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400,400);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Modul 5 - Tugas 4 - 160411100152");
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();
    return 0;
}
