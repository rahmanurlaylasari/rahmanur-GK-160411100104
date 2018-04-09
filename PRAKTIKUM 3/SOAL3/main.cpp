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
    glVertex2f(-15,0.0);
    glVertex2f(15,0.0);

    glVertex2f(0.0,15);
    glVertex2f(0.0,-15);
    glEnd();
}

void display(void){
    /* bersihkan layar */
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 1.0, 0.0);
    float t = 0.0;
    //f(x) = 1/14 (x+4)(x+1)(x-1)(x-3) + 0.5
    //f(x) = (x-3)(x-3)(x-1)(x)(x+2)(x+2)(x+3) / 14.

    glBegin(GL_POINTS);
    for(t = -10.0; t<=10.0; t+=0.01){
        glVertex3f (t, (t-3)*(t-3)*(t-1)*(t)*(t+2)*(t+2)*(t+3)/14, 0.0);
    }
    glEnd();
    koordinat();
    glFlush ();
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

void myinit(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-15.0,15.0,-15.0,15.0);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(0.0,0.0,0.0,0.0);
    //glColor3f (1.0, 1.0, 0.0);
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
