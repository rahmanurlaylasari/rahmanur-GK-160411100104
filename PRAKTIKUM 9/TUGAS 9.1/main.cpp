#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>

boolean diff = true, spec = true, amb = true;
float theta = 0.0;

void balok(){
    //glColor3f(r,g,b);
    glColor3f(0.7,0.7,0.6);
    glutSolidCube(2.5);
}

void satu(){
    //glColor3f(0.0,0.0,1.0);
    glPushMatrix();
    glScaled(1,2.5,1);
    balok();
    glPopMatrix();
    glEnd();
}

void nol(){
    //glColor3f(0.0,0.0,1.0);
    glPushMatrix();
    glScaled(1,2.5,1);
    glTranslated(4,0,0);
    glRotated(90,0,0,1);
    balok();
    glTranslated(0,8.5,0);
    balok();
    glTranslated(0.8,-2,0);
    glRotated(90,0,0,1);
    glScaled(1,0.35,1);
    balok();
    glTranslated(0,4.6,0);
    balok();
    glPopMatrix();
    glEnd();
}

void empat(){
    //glColor3f(0.0,0.0,1.0);
    glPushMatrix();
    glScaled(1,1.7,1);
    glTranslated(-8,0.6,0);
    glRotated(90,0,0,1);
    balok();
    glTranslated(-0.8,2,0);
    glRotated(90,0,0,1);
    glScaled(1,0.35,1);
    balok();
    glTranslated(2.0,-0.4,0);
    glRotated(90,0,0,1);
    glScaled(4.5,1.0,1);
    balok();
    glPopMatrix();
    glEnd();
}

void nim(){
satu();
nol();
empat();
}
void display()
{
 glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
 glLoadIdentity();
 glRotated(35, 1,1,1);
 GLfloat mat_specular[] = { 0.7, 0.7, 0.7, 1.0 };
 GLfloat mat_shininess[] = { 10.0 };
 GLfloat mat_diffuse[] = { 0.7, 0.7, 0.7, 1.0 };
 glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
 glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
 glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
 glRotatef(theta, 0,0.0001,0);
 //depan
//glPushMatrix();
//satu();
//glPopMatrix();
//
//glPushMatrix();
//nol();
//glPopMatrix();
//
//glPushMatrix();
//empat();
//glPopMatrix();

glPushMatrix();
glScaled(1,1.5,1);
nim();
glPopMatrix();

 glFlush();
}
void reshape (int w, int h)
{
 glViewport (0, 0, (GLsizei) w, (GLsizei) h);
 glMatrixMode (GL_PROJECTION);
 glLoadIdentity();
 if (w <= h)
 glOrtho (-15.0, 15.0, -15.0*(GLfloat)h/(GLfloat)w,
15.0*(GLfloat)h/(GLfloat)w, - 15.0, 15.0);
 else
 glOrtho (-10.5*(GLfloat)w/(GLfloat)h, 10.5*(GLfloat)w/(GLfloat)h, -
10.5, 10.5, -10.0, 10.0);
 glMatrixMode(GL_MODELVIEW);
 glLoadIdentity();
  }
void myinit()
{
 glClearColor (0.0, 0.0, 0.0, 0.0);
 glColor3f(0.0, 0.0, 0.0);
 GLfloat light_position_diff[] = { -1.0, 1.0, 1.0, 0.0 };
 GLfloat diffuse_light[] = { 0.0, 0.0, 1.0, 1.0 };
 GLfloat light_position_spec[] = { 1.0, 1.0, 1.0, 0.0 };
 GLfloat specular_light[] = { 0.0, 1.0, 0.0, 1.0 };
 GLfloat ambient_light[] = { 0.9, 0.9, 0.9, 1.0 };
 glLightfv(GL_LIGHT0, GL_POSITION, light_position_diff);
 glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
 glLightfv(GL_LIGHT1, GL_POSITION, light_position_spec);
 glLightfv(GL_LIGHT1, GL_SPECULAR, specular_light);
 glLightModelfv(GL_LIGHT_MODEL_AMBIENT,ambient_light);
 glEnable(GL_LIGHTING);
 glEnable(GL_DEPTH_TEST);
 glShadeModel (GL_SMOOTH);
 glEnable(GL_LIGHT0);
 glEnable(GL_LIGHT1);
}
 void myIdle(){
 theta +=0.03;
 display();
 }
 void mykey(unsigned char key, int mouseX, int mouseY){
 if (key=='1'){
 if (amb == true){
 GLfloat ambient_light[] = { 0.3, 0.3, 0.3, 1.0 };
 glLightModelfv(GL_LIGHT_MODEL_AMBIENT,ambient_light);
 amb = false;
 }
 else{
 GLfloat ambient_light[] = { 0.9, 0.9, 0.9, 1.0 };
 glLightModelfv(GL_LIGHT_MODEL_AMBIENT,ambient_light);
 amb = true;
 }
 }
 if (key=='2'){
 if (diff == true){
 glDisable(GL_LIGHT0);
 diff = false;
 }
 else{
 glEnable(GL_LIGHT0);
 diff = true;
 }
 }
 if (key=='3'){
 if (spec == true){
 glDisable(GL_LIGHT1);
 spec = false;
 }
 else{
 glEnable(GL_LIGHT1);
 spec = true;
 }
 }
 display();
 }
int main(int argc, char* argv[])
{
    glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
 glutInitWindowSize(600,600);
 glutInitWindowPosition(100,100);
 glutCreateWindow("Kotak");
 glutDisplayFunc(display);
 glutReshapeFunc(reshape);
 glutIdleFunc(myIdle);
 glutKeyboardFunc(mykey);
 myinit();
 glutMainLoop();
 return 0;
}
