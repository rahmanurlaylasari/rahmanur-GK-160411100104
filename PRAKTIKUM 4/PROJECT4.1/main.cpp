#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>

void checkerboardrect(int baris, int kolom){
    for (int i = 0; i<baris; i++){
        for (int j=0;j<kolom; j++){
            if((i+j)%2==0){
                glColor3f (1.0, 1.0, 1.0);//RGB
            }else{
                glColor3f (0.0, 0.0, 0.0);//RGB
            }
            glRotated(45,0,0,1);
            glTranslated(i,j,0);
            glRectf(0,0,1,1);
            glLoadIdentity();

        }
    }
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    checkerboardrect(20,20);
    glFlush();
}

void myinit(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-4.95,4.95,4.95,9.9);//kiri,kanan,bawah,atas
    glMatrixMode(GL_MODELVIEW);
    glClearColor(1.0,0.0,0.0,0.0);//CMYK
    glColor3f (1.0, 1.0, 1.0);//RGB
}
int main(int argc, char* argv[]){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    //glutInitWindowPosition(100,100);
    glutCreateWindow("Alphabet rect");
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();
    return 0;
}
