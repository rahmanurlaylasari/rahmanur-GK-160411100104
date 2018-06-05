#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

void kubusWarna(){
        glPushMatrix();
        glScaled(0.8,0.8,0.8);
         //depan
         glColor3f(0,0,1);
         glBegin(GL_POLYGON);
         glVertex3f(-3,-3,3);
         glVertex3f(3,-3,3);
         glVertex3f(3,3,3);
         glVertex3f(-3,3,3);
         glEnd();

         //belakang
         glColor3f(0,1,0);
         glBegin(GL_POLYGON);
         glVertex3f(3,-3,-3);
         glVertex3f(-3,-3,-3);
         glVertex3f(-3,3,-3);
         glVertex3f(3,3,-3);
         glEnd();

          //kiri
         glColor3f(1,0,1);
         glBegin(GL_POLYGON);
         glVertex3f(-3,-3,-3);
         glVertex3f(-3,-3,3);
         glVertex3f(-3,3,3);
         glVertex3f(-3,3,-3);
         glEnd();

          //kanan
         glColor3f(1,1,0);
         glBegin(GL_POLYGON);
         glVertex3f(3,-3,-3);
         glVertex3f(3,3,-3);
         glVertex3f(3,3,3);
         glVertex3f(3,-3,3);;
         glEnd();

         //bawah
         glColor3f(0,1,1);
         glBegin(GL_POLYGON);
         glVertex3f(3,-3,3);
         glVertex3f(-3,-3,3);
         glVertex3f(-3,-3,-3);
         glVertex3f(3,-3,-3);
         glEnd();

         //atas
         glColor3f(1,0,0);
         glBegin(GL_POLYGON);
         glVertex3f(-3,3,3);
         glVertex3f(3,3,3);
         glVertex3f(3,3,-3);
         glVertex3f(-3,3,-3);
         glEnd();
         glPopMatrix();
}

void objek() {
    glColor3f(0,0,1);
    glutWireCube(4.5); //Kubus Tengah

    glPushMatrix();
    glColor3f(1,1,0);
    glTranslated(0,20,0);
    glRotated(-90,1,0,0);
    glutWireCone(3.5, 7, 10, 10); //Cone atas
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.5, 0, 0.5);
    glTranslated(0,-20,0);
    glScaled(5,5,5);
    glRotated(90,0,0,1);
    glutWireTetrahedron(); //Tetrahedron Bawah
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,1,0);
    glTranslated(20,0,0);
    glutWireTeapot(3); //Teapot Kanan
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,0,0);
    glRotated(45,1,0,0);
    glTranslated(-20,0,0);
    glutWireSphere(3, 10, 10); //Bola Kiri
    glPopMatrix();

    glPushMatrix();
    glTranslated(0,0,20);
    glRotated(90,0,0,1);
    kubusWarna(); //Kubus depan
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.5,0.7,1);
    glTranslated(0,0,-20);
    glRotated(30,1,0,0);
    glRotated(5,0,1,0);
    glutWireSphere(3, 4, 2); //Sphere belakang
    glPopMatrix();
}

garis() {
    glColor3f(1,1,1);
    glBegin(GL_LINES);
    glVertex3f(0,20,0);
    glVertex3f(0,-20,0);
    glVertex3f(20,0,0);
    glVertex3f(-20,0,0);
    glVertex3f(0,0,20);
    glVertex3f(0,0,-20);
    glEnd();
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    glRotated(20,1,1,1);
    objek();
    garis();
    glPopMatrix();

    glFlush();
}

void init(void){
     glClearColor (0.0, 0.0, 0.0, 0.0);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     glOrtho(-30.0, 30.0, -30.0, 30.0, -30.0, 30.0);
     glMatrixMode(GL_MODELVIEW);
     glShadeModel (GL_FLAT);
     glEnable(GL_DEPTH_TEST);
    }

int main(int argc, char** argv){
     glutInit(&argc, argv);
     glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
     glutInitWindowSize(500, 500);
     glutInitWindowPosition(100, 100);
     glutCreateWindow("Modul 6 - Tugas 3 - Bag 1");
     init();
     //glutKeyboardFunc(kunci);
     glutDisplayFunc(display);
     glutMainLoop();

     return 0;
 }
