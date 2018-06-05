#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>

void koordinat (float r, float g, float b){
    glColor3f(r,g,b);
    glBegin(GL_LINES);
    glVertex3f(-25.0,0.0,0.0);
    glVertex3f(25.0,0.0,0.0);
    glVertex3f(0.0,-25.0,0.0);
    glVertex3f(0.0,25.0,0.0);
    glVertex3f(0.0,0.0,-25.0);
    glVertex3f(0.0,0.0,25.0);
    glEnd();
}

void kotak (float r, float g, float b){
    glColor3f(r,g,b);
    glBegin(GL_POLYGON);
    glVertex3f(-5.0,15.0,10.0);
    glVertex3f(5.0,15.0,10.0);
    glVertex3f(5.0,0.0,10.0);
    glVertex3f(-5.0,0.0,10.0);
    glEnd();
}

void persegi (float r, float g, float b){
    glColor3f(r,g,b);
    glBegin(GL_POLYGON);
    glVertex3f(5.0,0.0,10.0);
    glVertex3f(5.0,15.0,10.0);
    glVertex3f(5.0,15.0,-10.0);
    glVertex3f(5.0,0.0,-10.0);
    glEnd();
}

void segitiga (float r, float g, float b){
    glColor3f(r,g,b);
    glBegin(GL_POLYGON);
    glVertex3f(0.0,20.0,10.0);
    glVertex3f(-5.0,15.0,10.0);
    glVertex3f(5.0,15.0,10.0);
    glEnd();
}

void segiatap (float r, float g, float b){
    glColor3f(r,g,b);
    glBegin(GL_POLYGON);
    glVertex3f(0.0,20.0,12.0);
    glVertex3f(7.0,13.0,12.0);
    glVertex3f(7.0,13.0,-12.0);
    glVertex3f(0.0,20.0,-12.0);
    glEnd();
}

void lingkaran (float r, float g, float b){
    glColor3f(r,g,b);
    glutSolidSphere(0.9,8,8);
    glLoadIdentity();
    glEnd();
}

//void angka (float r, float g, float b){
//    glColor3f(r,g,b);
//    glBegin(GL_POLYGON);
//    glVertex3f(-5.1,11.5,-7);
//    glVertex3f(-5.1,11,-6.5);
//    glVertex3f(-5.1,11,-4);
//    glVertex3f(-5.1,11.5,-3.5);
//    glVertex3f(-5.1,12,-4);
//    glVertex3f(-5.1,12,-6.5);
//    glLoadIdentity();
//    glEnd();
//}

void depan (){
    glPushMatrix();
    kotak(0.0,1.0,0.0); // dinding hijau
    glTranslated(0.0,0.0,0.1);//pintu depan
    glScaled(0.5,0.70,1.0);
    kotak(0.3,0.0,0.7);
    glTranslated(0.0,0.0,-20.2);//pintu belakang
    kotak(0.3,0.0,0.7);
    glTranslated(-2.8,10.3,10.0);
    lingkaran(1.0,1.0,1.0);
    glPopMatrix();

    glPushMatrix();//pegangan pintu
    glTranslated(1.5,6.5,10.0);
    glScaled(0.6,0.65,1.0);
    lingkaran(1.0,1.0,1.0);//putih
    glPopMatrix();

    glPushMatrix();//untuk segitiga atap
    segitiga(0.0,1.0,0.0);//atap ijo
    glTranslated(0.0,0.0,-20.0);
    segitiga(0.0,1.0,0.0);
    glPopMatrix();

    glPushMatrix();//segitiga atap di atap depan
    glTranslated(0.25,1.0,0.1);
    glScaled(0.9,0.9,1.0);
    segitiga(0.6,0.6,0.0);
    glTranslated(0.0,0.0,-20.2);
    segitiga(0.6,0.6,0.0);
    glPopMatrix();
    glLoadIdentity();
    glEnd();
}

void sampingkanan (){
    glPushMatrix();
    persegi(0.9,0.5,0.0);//0range
    //jendela tengah
    glRotated(120,1,1,1);
    glScaled(0.7,0.3,0.5);
    glTranslated(13.0,-7.75,0.1);
    kotak(0.6,0.3,0.0);
    //jendela kiri
    glTranslated(0.0,20.0,0.0);//y,x,z
    kotak(0.6,0.3,0.0);
    //jendela kanan
    glTranslated(0.0,-40.2,0.0);//y,x,z
    kotak(0.6,0.3,0.0);
    glPopMatrix();

    glPushMatrix();
    glRotated(120,1,1,1);
    glScaled(0.53,0.2,0.51);
    glTranslated(17.0,-7.75,0.0);
    kotak(0.9,0.9,1.0);
    //jendela kiri
    glTranslated(0.0,30.0,0.0);//y,x,z
    kotak(0.9,0.9,1.0);
    //jendela kanan
    glTranslated(0.0,-60.5,0.1);//y,x,z
    kotak(0.9,0.9,1.0);
    glPopMatrix();
    glEnd();
}

void sampingkiri (){
    glPushMatrix();
    glTranslated(-10.0,0.0,0.0);
    persegi(0.9,0.5,0.0);//orange
    glPopMatrix();

    glPushMatrix();//nim angka 0
    glTranslated(-6.18,10.0,-2.1);//x,atas, samping
    glRotated(120,1.0,1.0,1.0);
    glScaled(0.1,0.2,0.1);
    kotak(1.0,1.0,1.0);//putih
    glTranslated(-2.1,1.92,-1.0);//x,atas, samping
    glRotated(90,0.0,0.0,1.0);
    glScaled(0.39,3.0,1.1);
    kotak(1.0,1.0,1.0);//putih
    glTranslated(28.0,0.5,-1.0);//x,atas, samping
    glScaled(1.0,1.0,1.1);
    kotak(1.0,1.0,1.0);//putih
    glTranslated(5.1,16.0,-1.0);//x,atas, samping
    glRotated(90,0.0,0.0,1.0);
    glScaled(0.32,2.5,1.1);
    kotak(1.0,1.0,1.0);//putih
    glPopMatrix();

    glPushMatrix();//nim angka 4
    glTranslated(-6.1,7.4,2.0);//x,atas, samping
    glRotated(120,1.0,1.0,1.0);
    glScaled(0.1,0.15,0.1);
    kotak(1.0,1.0,1.0);//putih
    glTranslated(30.0,14.5,-1.0);//x,atas, samping
    glRotated(90,0.0,0.0,1.0);
    glScaled(0.39,4.0,1.1);
    kotak(1.0,1.0,1.0);//putih
    glTranslated(-39.0,0.0,-0.9);//x,atas, samping
    glScaled(1.2,0.58,1.0);
    kotak(1.0,1.0,1.0);//putih
    glPopMatrix();

    glPushMatrix();//nim angka 1
    glTranslated(-16.1,4.2,-3.4);//x,atas, samping
    glRotated(90,0.0,1.0,0.0);
    glScaled(0.075,0.42,1.1);
    kotak(1.0,1.0,1.0);//putih
    glPopMatrix();
}

void belakang (){
    glPushMatrix();
    glTranslated(0.0,0.0,-20.0);
    kotak(0.0,1.0,0.0);//ijo
    glPopMatrix();

    glPushMatrix();
    //L
    glTranslated(1.5,11.0,-11.1);//x,atas, samping
    glScaled(0.07,0.17,0.1);
    kotak(1.0,0.0,1.0);//ungu
    glTranslated(4.0,1.5,10.1);
    glRotated(90,0.0,0.0,0.1);
    glScaled(0.35,1.10,0.0);
    kotak(1.0,0.0,1.0);
    glPopMatrix();
//y
    glPushMatrix();
    glTranslated(-1.0,11.0,-11.1);//x,atas, samping
    glScaled(0.065,0.10,0.1);
    kotak(1.0,0.0,1.0);//ungu
    glTranslated(-3.0,5.0,10.1);//atas
    glRotated(-40.0,0.0,0.0,0.1);
    glScaled(0.7,1.65,0.0);
    kotak(1.0,0.0,1.0);
    glTranslated(-3.0,4.65,10.1);//atas
    glRotated(90.0,0.0,0.0,0.1);
    glScaled(0.43,1.65,0.0);
    kotak(1.0,0.0,1.0);
    glPopMatrix();
}

void atap (){
    glPushMatrix();
    segiatap(1.6,0.3,0.0);//orenye
    glRotated(90,0,0,1);
    glTranslated(13.0,-13.0,0.0);
    segiatap(1.6,0.3,0.0);//orenye
    glPopMatrix();

    glPushMatrix();//kayu atap kiri
    glTranslated(0.4,20.5,2.0);
    glRotated(135,0,0,1);
    glScaled(0.1,0.7,1.0);
    kotak(0.6,0.3,0.0);//coklat
    glTranslated(0.0,0.0,-24.0);
    kotak(0.6,0.3,0.0);
    glPopMatrix();

    glPushMatrix();//kayu atap kanan
    glTranslated(7.3,13.3,2.0);
    glRotated(45,0,0,1);
    glScaled(0.1,0.7,1.0);
    kotak(0.6,0.3,0.0);//coklat
    glTranslated(0.0,0.0,-24.0);
    kotak(0.6,0.3,0.0);
    glPopMatrix();
    glEnd();
}

void teras(){
    glPushMatrix();
    glRotated(119.5,1.0,1.0,1.);
    glScaled(1.0,2.5,1.0);
    glTranslated(-5.2,-5.0,-0.5);//atas,depan
    persegi(0.7,0.6,0.2);
    glPopMatrix();
    glEnd();
}

void display()
{
glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
    koordinat(1.0,1.0,1.0);

    glPushMatrix();
    depan();
    glPopMatrix();

    glPushMatrix();
    sampingkanan();
    glPopMatrix();

    glPushMatrix();
    sampingkiri();
    glPopMatrix();

    glPushMatrix();
    belakang();
    glPopMatrix();

    glPushMatrix();
    atap();
    glPopMatrix();

    glPushMatrix();
    teras();
    glPopMatrix();
glFlush();
}
void kunci(unsigned char key, int x, int y){
    switch (key){
    case 'q':
    exit(0);
    break;

    case 'a':
    glRotated(5,1,0,0);
    display();
    break;

    case 's':
    glRotated(1,0,1,0);
    display();
    break;

    case 'd':
    glRotated(1,0,0,1);
    display();
    break;
    }
glutPostRedisplay();
}

void myinit(){
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-15.0,15.0,-10.0,25.0,-75.0,75.0);
glMatrixMode(GL_MODELVIEW);
glClearColor(0.0,0.0,0.0,0.2);
glColor3f(1.0,1.0,1.0);
glShadeModel(GL_FLAT);
glEnable(GL_DEPTH_TEST);
}

int main(int argc, char* argv[]){
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
glutInitWindowSize(750,600);
glutInitWindowPosition(100,100);
glutCreateWindow("KotakBersilang");
glutDisplayFunc(display);
myinit();
glutKeyboardFunc(kunci);
glutMainLoop();
return 0;
}
