#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3d(1,1,0);
    for (int x=0; x<4; x++){
        if (x==0) {
            glTranslated(0,0,0);
        } else {
            glTranslated(0,-14,0);
        }

        glPushMatrix();
        for (int i=0; i<5; i++) {
            if (i==0) {
                glTranslated(0,0,0);
            } else if (0>i<4){
                glTranslated(14,0,0);
            }
            glPushMatrix();
            glRotated(45,0,0,1);
            glRectd(-5,-5,5,5);
            glPopMatrix();
        }
        glPopMatrix();
    }
    glFlush();

}
void myinit() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-0.0, 56.0, -49.0, 7.0);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(0.0,0.0,1.0,1.0);
}
int main(int argc, char* argv[]) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400,400);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Modul 5 - Tugas 1 - 160411100152");
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();
    return 0;
}
