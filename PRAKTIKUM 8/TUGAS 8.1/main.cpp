#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;

float warna[] = {0.0, 0.0, 0.0}, counter=0;
float wG[] = {1.0, 1.0, 1.0};


void input(int key, int x, int y){
    switch(key) {
    case GLUT_KEY_UP:
        if (counter < 1) {
            warna[0] += 0.1;
            wG[0] -= 0.1;
            counter+= 0.1;
        }else if (counter >= 1 && counter <2){
            warna[0] -= 0.1;
            warna[1] += 0.1;
            wG[0] += 0.1;
            wG[1] -=0.1;
            counter += 0.1;
        } else if (counter >= 2) {
            warna[1] -= 0.1;
            warna[2] += 0.1;
            wG[1] += 0.1;
            wG[2] -= 0.1;
            if (warna[1]<=0){
                warna[1]=0;
                wG[1]=1;
            }
            if (warna[2]>=1){
                warna[2]=1;
                wG[2]=0;
            }
        }
        break;
    case GLUT_KEY_DOWN:
        if (counter > 1) {
            warna[1] += 0.1;
            warna[2] -= 0.1;
            wG[1] -= 0.1;
            wG[2] += 0.1;
            counter -= 0.1;
        } else if (counter <= 1 && counter >0) {
            warna[0] += 0.1;
            warna[1] -= 0.1;
            wG[0] -= 0.1;
            wG[1] += 0.1;
            counter -=0.1;
        } else if(counter <= 0) {
            warna[0] -= 0.1;
            wG[0] += 0.1;
            if (warna[0] <= 0) {
                warna[0] = 0;
                wG[0] = 1;
            }
        }
        break;
    }
    glutPostRedisplay();
}

void garis(float r, float g, float b) {
    glLineWidth(5);
    glColor3f(r,g,b);
    glBegin(GL_LINE_LOOP);
    glVertex3f(-6.5, 1.5, 0);
    glVertex3f(6.5, 1.5, 0);
    glVertex3f(-4, -6.3, 0);
    glVertex3f(0, 6 ,0);
    glVertex3f(4, -6.3, 0);
    glEnd();
}

void bintang(float r, float g, float b){
    glColor3f(r,g,b);
    glBegin(GL_POLYGON);
    glVertex3f(1.5, 1.5, 0);
    glVertex3f(6.5, 1.5, 0);
    glVertex3f(2.5, -1.5, 0);
    glVertex3f(4, -6.3, 0);
    glVertex3f(0, -3.4, 0);
    glVertex3f(-4, -6.3, 0);
    glVertex3f(-2.5, -1.5, 0);
    glVertex3f(-6.5, 1.5, 0);
    glVertex3f(-1.5, 1.5, 0);
    glVertex3f(0, 6, 0);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    garis(wG[0], wG[1], wG[2]);
    bintang(warna[0], warna[1], warna[2]);

    glEnd();
    glutSwapBuffers();
}

void init(void)
{
    glClearColor (0.9, 0.9, 0.9, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glShadeModel (GL_FLAT);
    glEnable(GL_DEPTH_TEST);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Modul 8 - Tugas 1");
    init();
    glutSpecialFunc(input);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
