#include <windows.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <math.h>
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
    float x = 0.0;
    glBegin(GL_LINE_STRIP);
    //perhitungan sudut di openGL menggunakan radian, bukan derajat
    //y = A=3 Cos(B=4x + C=0.5) + D=2
    for(x=0.0; x<=6.28; x+=0.01){
        glVertex2f(x,3*cos(4*x+0.5)+2);
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
    gluOrtho2D(-10.0,10.0,-10.0,10.0);
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
