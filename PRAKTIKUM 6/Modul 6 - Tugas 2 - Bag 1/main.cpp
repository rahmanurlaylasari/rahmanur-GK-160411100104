#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

void objek() {
    glPushMatrix();
    glRotated(45,0,0,1);
    glColor3d(0,1,0);
    glBegin(GL_POLYGON); //Belakang +
    glVertex3f(1.0, 1.0, -1.0);
    glVertex3f(4.0, 1.0, -1.0);
    glVertex3f(4.0, -1.0, -1.0 );
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(1.0, -4.0, -1.0);
    glVertex3f(-1.0, -4.0, -1.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-4.0, -1.0, -1.0);
    glVertex3f(-4.0, 1.0, -1.0);
    glVertex3f(-1.0,1.0, -1.0);
    glVertex3f(-1.0, 4.0, -1.0);
    glVertex3f(1.0, 4.0, -1.0);
    glEnd();

    glColor3d(0,0,1);
    glBegin(GL_POLYGON); //Depan +
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(4.0, 1.0, 1.0);
    glVertex3f(4.0, -1.0, 1.0 );
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(1.0, -4.0, 1.0);
    glVertex3f(-1.0, -4.0, 1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(-4.0, -1.0, 1.0);
    glVertex3f(-4.0, 1.0, 1.0);
    glVertex3f(-1.0,1.0, 1.0);
    glVertex3f(-1.0, 4.0, 1.0);
    glVertex3f(1.0, 4.0, 1.0);
    glEnd();

    glColor3d(1,0,0); //atas
    glBegin(GL_POLYGON);
    glVertex3d(-1, 4, 1);
    glVertex3d(1, 4, 1);
    glVertex3d(1, 4, -1);
    glVertex3d(-1, 4, -1);
    glEnd();

    glBegin(GL_POLYGON); //kiri
    glVertex3d(-4, -1, 1);
    glVertex3d(-4, 1, 1);
    glVertex3d(-4, 1, -1);
    glVertex3d(-4, -1, -1);
    glEnd();

    glColor3f(0.5, 1, 1); //kanan
    glBegin(GL_POLYGON);
    glVertex3d(4, -1, 1);
    glVertex3d(4, 1, 1);
    glVertex3d(4, 1, -1);
    glVertex3d(4, -1, -1);
    glEnd();

    glBegin(GL_POLYGON); //bawah
    glVertex3d(-1, -4, 1);
    glVertex3d(1, -4, 1);
    glVertex3d(1, -4, -1);
    glVertex3d(-1, -4, -1);
    glEnd();

    glColor3f(1,1,0); //Kuning 2 di kanan atas
    glBegin(GL_POLYGON);
    glVertex3d(1, 4, 1);
    glVertex3d(1, 4, -1);
    glVertex3d(1, 1, -1);
    glVertex3d(1, 1, 1);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3d(1, 1, 1);
    glVertex3d(1, 1, -1);
    glVertex3d(4, 1, -1);
    glVertex3d(4, 1, 1);
    glEnd();

    glBegin(GL_POLYGON); //Kuning bawah kanan vertikal
    glVertex3d(1, -1, 1);
    glVertex3d(1, -1, -1);
    glVertex3d(1, -4, -1);
    glVertex3d(1, -4, 1);
    glEnd();

    glBegin(GL_POLYGON); //Kuning kiri atas horizontal
    glVertex3d(-4, 1, 1);
    glVertex3d(-4, 1, -1);
    glVertex3d(-1, 1, -1);
    glVertex3d(-1, 1, 1);
    glEnd();


    glColor3f(1,0,1); //Pink 2 di kiri bawah
    glBegin(GL_POLYGON);
    glVertex3d(-4, -1, 1);
    glVertex3d(-4, -1, -1);
    glVertex3d(-1, -1, -1);
    glVertex3d(-1, -1, 1);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3d(-1, -1, 1);
    glVertex3d(-1, -1, -1);
    glVertex3d(-1, -4, -1);
    glVertex3d(-1, -4, 1);
    glEnd();

    glBegin(GL_POLYGON); //Pink atas kiri vertikal
    glVertex3d(-1, 4, 1);
    glVertex3d(-1, 4, -1);
    glVertex3d(-1, 1, -1);
    glVertex3d(-1, 1, 1);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3d(4, -1, 1);
    glVertex3d(4, -1, -1);
    glVertex3d(1, -1, -1);
    glVertex3d(1, -1, 1);
    glEnd();
    glPopMatrix();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glRotated(25, 1,0,0);
    objek();
    glPopMatrix();

    glFlush();
}

void myinit(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-5.0,5.0,-5.0,5.0,-5.0,5.0);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(0.0,0.0,0.0,1.0);
    glColor3f(0.0,0.0,0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
}

int main(int argc, char* argv[]){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(400,400);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Modul 6 - Tugas 2 | Bag 1 - (152)");
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();

    return 0;
}
