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
    glColor3d(0,0,1);

    int derajat = 30;
    for (int i=0; i<12; i++) {
        glPushMatrix();
        glRotated(derajat, 0, 0, 1);
        glTranslated(0, 40, 0);
        glScaled(0.95, 0.95, 0);
        glRectd(-5, -5, 5, 5);
        glPopMatrix();
        derajat = derajat + 30;
    }

    glBegin(GL_LINES);
    glColor3f (1, 1.0, 0.0);
    for(float i = 0; i<=3.14*2; i+=0.01){
        glVertex2f(40*cos(i),40*sin(i));
    }
    glEnd();

    glFlush();
}
void myinit() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-50.0, 50.0, -50.0, 50.0);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(0.0,0.0,0.0,1.0);
}
int main(int argc, char* argv[]) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400,400);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Modul 5 - Tugas 2 - 160411100152");
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();
    return 0;
}
