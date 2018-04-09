#include <windows.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void koordinat(){
    //glPointSize(10);
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_LINES);
    glVertex2f(-10,0.0);
    glVertex2f(10,0.0);

    glVertex2f(0.0,10);
    glVertex2f(0.0,-10);
    glEnd();
}

void display(void){
    /* bersihkan layar */
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 1.0, 0.0);
    float t = 0.0;

    glBegin(GL_LINE_STRIP);
    for(t = -5.0; t<=5.0; t+=0.01){
        /* x(t) = -1 + 2t; y(t) = 0 */
        glVertex3f (-0.5+t*t,t, 0.0);
    }
    glEnd();
    koordinat();
    glFlush ();
}

void myinit(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-5.0,5.0,-5.0,5.0);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(0.0,0.0,0.0,0.0);
    //glColor3f (1.0, 1.0, 0.0);
}

void kunci(unsigned char key, int x, int y){
    switch (key){
        /* aplikasi berhenti ketika tombol q ditekan */
        case 27 :
        case 'q':
        exit(0);
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char *argv[]){
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Primitif");
    glutDisplayFunc(display);
    glutKeyboardFunc(kunci);
    myinit();
    glutMainLoop();
    return 0;
}
