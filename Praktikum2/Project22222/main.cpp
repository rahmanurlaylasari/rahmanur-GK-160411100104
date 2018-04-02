#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

void display(){
 glClear(GL_COLOR_BUFFER_BIT);
    glColor3f (0.0, 0.0, 1.0);
     for(int x = -1; x<=0; x++){
            for(int y = 0; y<= 1; y++){
                glRecti(-1, x, 0, y);
            }
        glColor3f (0.0, 1.0, 1.0);
     }
     glColor3f (0.0, 1.0, 1.0);

     for(int x = -1; x<=0; x++){
            for(int y = 0; y<= 1; y++){
                glRecti(0, x, 1, y);
            }
        glColor3f (0.0, 0.0, 1.0);
     }
     // Huruf B
     glColor3f(1.0, 1.0, 1.0);
     glRectf(-0.7, 0.1, -0.5, 0.9);
     glRectf(-0.7, 0.8, -0.2, 0.9);
     glRectf(-0.7, 0.45, -0.2, 0.55);
     glRectf(-0.7, 0.1, -0.2, 0.2);
     glRectf(-0.3, 0.2, -0.2, 0.9);

    // Huruf E
    glRectf(0.25, 0.15, 0.4, 0.85);
    glRectf(0.4, 0.7, 0.75, 0.85);
    glRectf(0.25, 0.5, 0.75, 0.6);
    glRectf(0.4, 0.15, 0.75, 0.3);

    // Huruf L
    glRectf(-0.7, -0.85, -0.5, -0.15);
    glRectf(-0.7, -0.85, -0.2, -0.7);

    //Huruf A
    glRectf(0.2, -0.85, 0.4, -0.15);
    glRectf(0.2, -0.3, 0.8, -0.15);
    glRectf(0.6, -0.85, 0.8, -0.15);
    glRectf(0.2, -0.6, 0.8, -0.5);

 glFlush();
}
void myinit(){
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluOrtho2D(-1.5,1.5,-1.5,1.5);
 glMatrixMode(GL_MODELVIEW);
 glClearColor(0.0,0.0,0.0,0.0);

}
int main(int argc, char* argv[]){
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize(500,500);
 //glutInitWindowPosition(100,100);
 glutCreateWindow("Primitif Bangun Datar");
 glutDisplayFunc(display);
 myinit();
 glutMainLoop();
 return 0;
}
