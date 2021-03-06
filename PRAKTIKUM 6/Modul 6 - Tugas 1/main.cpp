#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

void display(void){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glScaled(-1,1,1);

    glRotated(25,1,0,0);
    glRotated(45,0,0,1);
    glScaled(4,1,1);
    glutWireCube(2);

    glLoadIdentity();
    glRotated(25, 1,0,0);
    glRotated(45,0,0,1);
    glScaled(4,1,1);
    glutWireCube(2);

    glPopMatrix();
    glFlush();
}

void init(void){
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-5.0, 5.0, -5.0, 5.0, -5.0, 5.0);
    glMatrixMode(GL_MODELVIEW);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Modul 6 - Tugas 1 - X Cube (152)");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
