#include <windows.h>
#ifdef __APPLE__
#include <iostream>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<math.h>

boolean diff = true, spec = true, amb = true;
float theta = 0.0;
static GLfloat spin = 0.0;
int a = 0;
bool b= true;
void nol()
{
    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    glVertex3f(-7.0, 3.0,1);
    glVertex3f(-7.0, 2.0,1);
    glVertex3f(-3.0, 2.0,1);
    glVertex3f(-3.0, 3.0,1);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    glVertex3f(-7.0, 3.0,1);
    glVertex3f(-7.0, -3.0,1);
    glVertex3f(-6.0, -3.0,1);
    glVertex3f(-6.0, 3.0,1);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    glVertex3f(-7.0, -2.0,1);
    glVertex3f(-3.0, -2.0,1);
    glVertex3f(-3.0, -3.0,1);
    glVertex3f(-7.0, -3.0,1);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    glVertex3f(-4.0, 3.0,1);
    glVertex3f(-3.0, 3.0,1);
    glVertex3f(-3.0, -3.0,1);
    glVertex3f(-4.0, -3.0,1);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    glVertex3f(-7.0, 3.0,-1);
    glVertex3f(-7.0, 2.0,-1);
    glVertex3f(-3.0, 2.0,-1);
    glVertex3f(-3.0, 3.0,-1);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    glVertex3f(-7.0, 3.0,-1);
    glVertex3f(-7.0, -3.0,-1);
    glVertex3f(-6.0, -3.0,-1);
    glVertex3f(-6.0, 3.0,-1);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    glVertex3f(-7.0, -2.0,-1);
    glVertex3f(-3.0, -2.0,-1);
    glVertex3f(-3.0, -3.0,-1);
    glVertex3f(-7.0, -3.0,-1);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    glVertex3f(-4.0, 3.0,-1);
    glVertex3f(-3.0, 3.0,-1);
    glVertex3f(-3.0, -3.0,-1);
    glVertex3f(-4.0, -3.0,-1);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    glVertex3f(-7.0, 3.0,1);
    glVertex3f(-3.0, 3.0,1);
    glVertex3f(-3.0, 3.0,-1);
    glVertex3f(-7.0, 3.0,-1);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    glVertex3f(-7.0, 3.0,1);
    glVertex3f(-7.0, -3.0,1);
    glVertex3f(-7.0, -3.0,-1);
    glVertex3f(-7.0, 3.0,-1);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    glVertex3f(-7.0, -3.0,1);
    glVertex3f(-3.0, -3.0,1);
    glVertex3f(-3.0, -3.0,-1);
    glVertex3f(-7.0, -3.0,-1);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    glVertex3f(-3.0, 3.0,1);
    glVertex3f(-3.0, -3.0,1);
    glVertex3f(-3.0, -3.0,-1);
    glVertex3f(-3.0, 3.0,-1);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    glVertex3f(-6.0, 2.0,1);
    glVertex3f(-4.0, 2.0,1);
    glVertex3f(-4.0, 2.0,-1);
    glVertex3f(-6.0, 2.0,-1);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    glVertex3f(-6.0, 2.0,1);
    glVertex3f(-6.0, -2.0,1);
    glVertex3f(-6.0, -2.0,-1);
    glVertex3f(-6.0, 2.0,-1);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    glVertex3f(-6.0, -2.0,1);
    glVertex3f(-4.0, -2.0,1);
    glVertex3f(-4.0, -2.0,-1);
    glVertex3f(-6.0, -2.0,1);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(0.0,0.0,1.0);
    glVertex3f(-4.0, 2.0,1);
    glVertex3f(-4.0, -2.0,1);
    glVertex3f(-4.0, -2.0,-1);
    glVertex3f(-4.0, 2.0,-1);
    glEnd();
}

void noll()
{
glTranslated(6,0,0);
nol();
}

void delapan()
{
glPushMatrix();
glTranslated(6,0,0);
nol();
glPopMatrix();

glPushMatrix();
    glBegin(GL_POLYGON);//tengah depan
    glNormal3f(0.0,0.0,1.0);
    glVertex3f(0.0, -0.5, 1);
    glVertex3f(2.0, -0.5, 1);
    glVertex3f(2.0, 0.5, 1);
    glVertex3f(0.0, 0.5, 1);
    glEnd();

    glBegin(GL_POLYGON);//tengah belakang
    glNormal3f(0.0,0.0,1.0);
    glVertex3f(0.0, -0.5, -1);
    glVertex3f(2.0, -0.5, -1);
    glVertex3f(2.0, 0.5, -1);
    glVertex3f(0.0, 0.5, -1);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(0,0,1);
    glVertex3f(0, -0.5, -1);
    glVertex3f(0, -0.5, 1);
    glVertex3f(2, -0.5, 1);
    glVertex3f(2, -0.5, -1);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(0,0,1);
    glVertex3f(0, 0.5, -1);
    glVertex3f(0, 0.5, 1);
    glVertex3f(2, 0.5, 1);
    glVertex3f(2, 0.5, -1);
    glEnd();
glPopMatrix();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    GLfloat mat_specular[] = { 0.7, 0.7, 0.7, 1.0 };
    GLfloat mat_shininess[] = { 10.0 };
    GLfloat mat_diffuse[] = { 0.7, 0.7, 0.7, 1.0 };
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glRotatef(theta, 0,1,0);

    glPushMatrix();
    if(a == 1)
    {
        glRotatef(spin, 0.0, 0.0, 1.0);
    }
    else if(a == 2)
    {
        glRotatef(spin, 0.0, 1.0, 0.0);
    }
    else if(a == 3)
    {
        glRotatef(spin, 1.0, 0.0, 0.0);
    }

    nol();
    noll();
    delapan();
    glPopMatrix();
    glutSwapBuffers();

    glFlush();
}
void reshape (int w, int h)
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho (-10, 10, -10*(GLfloat)h/(GLfloat)w,
                 10*(GLfloat)h/(GLfloat)w, - 10.0, 10.0);
    else
        glOrtho (-10*(GLfloat)w/(GLfloat)h, 7*(GLfloat)w/(GLfloat)h, -
                 10, 10, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void spinDisplay(void)
{
    spin = spin + 0.03;
    if (spin > 360.0)
        spin = spin - 360.0;
    glutPostRedisplay();
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
    glLightfv(GL_LIGHT2, GL_POSITION, light_position_diff);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, diffuse_light);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,ambient_light);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    glShadeModel (GL_SMOOTH);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
}
void myIdle()
{
    theta +=0.03;
    display();
}
void mykey(unsigned char key, int mouseX, int mouseY)
{
    if (key=='1')
    {
        if (amb == true)
        {
            GLfloat ambient_light[] = { 0.3, 0.3, 0.3, 1.0 };
            glLightModelfv(GL_LIGHT_MODEL_AMBIENT,ambient_light);
            amb = false;
        }
        else
        {
            GLfloat ambient_light[] = { 0.9, 0.9, 0.9, 1.0 };
            glLightModelfv(GL_LIGHT_MODEL_AMBIENT,ambient_light);
            amb = true;
        }
    }
    if (key=='2')
    {
        if (diff == true)
        {
            glDisable(GL_LIGHT0);
            diff = false;
        }
        else
        {
            glEnable(GL_LIGHT0);
            diff = true;
        }
    }
    if (key=='3')
    {
        if (spec == true)
        {
            glDisable(GL_LIGHT1);
            spec = false;
        }
        else
        {
            glEnable(GL_LIGHT1);
            spec = true;
        }
    }
    display();
}

void mouse(int button, int state, int x, int y)
{
    switch (button)
    {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN)
            a = 1;
            glutIdleFunc(spinDisplay);
        break;
    case GLUT_MIDDLE_BUTTON:
        if (state == GLUT_DOWN)
            a = 2;
            glutIdleFunc(spinDisplay);
        break;
    case GLUT_RIGHT_BUTTON:
        if (state == GLUT_DOWN)
            a = 3;
            glutIdleFunc(spinDisplay);
        break;
    default:
        break;
    }
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
    glutMouseFunc(mouse);
    myinit();
    glutMainLoop();
    return 0;
}
