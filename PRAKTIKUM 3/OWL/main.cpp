#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

#include <Math.h>

void myinit(){
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glColor3f(0.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10.0, 40.0, -5.0, 45.0);
    glMatrixMode(GL_MODELVIEW);
}

void display(void){
    /* bersihkan layar */
    glClear (GL_COLOR_BUFFER_BIT);


    float x = 0.0;

    for (float i=0; i<5; i+=1) { // kaki
        float rd = 5.65;
        glBegin(GL_POLYGON);
        for (x=0.0+(rd*i); x<=5.65+(rd*i)+0.1; x+=0.1) {
        glColor3f (1.0, 1.0, 1.0);
                //y = A Cos(Bx + C) + D
            glVertex2f(x,(0.8*cos(1.097*x-0))-0.5);
        }
        glEnd();
    }

    glBegin(GL_POLYGON);
    glColor3f (1.0, 0.0, 1.0);
    for(x = 0.0; x<=32; x+=0.1){ //badan_kanan
        /* x(t) = -1 + 2t; y(t) = 0 */
        glVertex2f (28.26-0.0075*x*(x-32), x);
    }

    for(x = 28.26; x>=0; x-=0.1){ //badan_kiri
        /* x(t) = -1 + 2t; y(t) = 0 */
        glVertex2f (x, 32-0.02*x*(x-28.26));
    }

    for(x = 28.26; x>=0; x-=0.1){ //badan_atas
        /* x(t) = -1 + 2t; y(t) = 0 */
        glVertex2f (0.0075*x*(x-32),x);
    }

   glEnd();
    glBegin(GL_POLYGON); //MATA_KIRI
    glColor3f (1.0, 1.0, 1.0);
    for(x=0; x<=6.28; x+=0.01){
        glVertex2f(cos(x)*3.5+9, sin(x)*3.5+23);
    }
    glEnd();

    glBegin(GL_POLYGON); //MATA_KANAN
    for(x=0; x<=6.28; x+=0.01){
        glVertex2f(cos(x)*3.5+19, sin(x)*3.5+23);
    }
    glEnd();

    glColor3f(0.0, 0.0, 0.0); // bola_mata_kanan
    glBegin(GL_POLYGON);
    for(x=0; x<=6.28; x+=0.01){
        glVertex2f(cos(x)*2+19, sin(x)*2+23);
    }
    glEnd();

    glBegin(GL_POLYGON); //bola_mata_kiri
    for(x=0; x<=6.28; x+=0.01){
        glVertex2f(cos(x)*2+9, sin(x)*2+23);
    }
    glEnd();

    glBegin(GL_POLYGON); //hidung
    glColor3f(0.0, 0.5, 0.5);
    for(x=0; x<=6.28; x+=0.01){
        glVertex2f(cos(x)*2+14, sin(x)*4+16);
    }
    glEnd();

   glColor3f(1.0, 1.0, 1.0); //MULUT
    glBegin(GL_POLYGON);
    for(x=0; x<=3.14; x+=0.01){
        glVertex2f(cos(x)*9+14, -sin(x)*8+10);
    }
    glEnd();

    glColor3f(1.0, 0.0, 0.0); //lidah_merah
    glBegin(GL_POLYGON);
    for(x=0.2; x<=2.94; x+=0.01){
       glVertex2f(cos(x)*9+14, -sin(x)*8+10);
    }
    glEnd();

    glColor3f(1.0, 1.0, 1.0); //lidah_bawah
    glBegin(GL_POLYGON);
    for(x=1.0; x<=2.14; x+=0.01){
        glVertex2f(cos(x)*9+14, -sin(x)*8+10);
    }
    glEnd();



    glColor3f(0.0, 1.0, 1.0);
    glBegin(GL_TRIANGLES); //telinga_luar_kanan
    glVertex2f(32.0, 38.0);
    glVertex2f(22.0, 30.0);
    glVertex2f(33.0, 26.0);
    glEnd();

    glBegin(GL_TRIANGLES); //telinga_luar_kiri
    glVertex2f(-4.0, 38.0);
    glVertex2f(-5.0, 26.0);
    glVertex2f(6.0, 30.0);
    glEnd();

    glColor3f(1.0, 1.0, 1.0); //telinga_dalam_kanan
    glBegin(GL_TRIANGLES);
    glVertex2f(30.25, 34.0);
    glVertex2f(24, 29.2);
    glVertex2f(31.0, 26.7);
    glEnd();

    glBegin(GL_TRIANGLES); //telinga_dalam_kiri
    glVertex2f(-2.3, 34.0);
    glVertex2f(-3.3, 26.7);
    glVertex2f(3.7, 29.2);
    glEnd();

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

int main(int argc, char *argv[]){
    glutInitWindowSize(400,400);
    glutInitWindowPosition(100,100);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Primitif");
    glutDisplayFunc(display);
    //glutKeyboardFunc(kunci);
    myinit();
    glutMainLoop();
    return 0;
}
