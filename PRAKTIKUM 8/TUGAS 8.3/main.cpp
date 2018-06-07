#include <windows.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

static GLfloat spin = 0.0;

void papan1(float putar) {
    glPushMatrix();
    glRotated(putar,0,0,1);
    glTranslated(-1,0,0);
    for (int i=0; i<4; i++) {
            glColor3d(1,0,0);
            glRectd(-7+4*i,-1,-5+4*i,1);
            glColor3d(1,1,1);
            glRectd(-5+4*i,-1,-3+4*i,1);
    }
    glPopMatrix();
}
void papan(){
    for (int i=0; i<4; i++) {
        glPushMatrix();
        glTranslated(0,7-4*i, 0);
        papan1(0);
        glPopMatrix();
    }
    for (int i=0; i<3; i++) {
        glPushMatrix();
        glTranslated(0,5-4*i, 0);
        papan1(180);
        glPopMatrix();
    }
}


void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotatef(spin, 0.0, 0.0, 1.0);

    glPushMatrix();
    glTranslated(1,-1,0);
    papan();
    glPopMatrix();

    glColor3d(0,0,0);
    glRectd(7,-7,9,7);
    glPopMatrix();

    glutSwapBuffers();
}

void spinDisplay(void) {
    spin = spin + 0.01;
    if (spin > 360.0)
        spin = spin - 360.0;
    glutPostRedisplay();
}

void init(void) {
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_FLAT);
}

void reshape(int w, int h){
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-7.0, 7.0, -7.0, 7.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void mouse(int button, int state, int x, int y) {
    switch (button)
    {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN)
            glutIdleFunc(spinDisplay);
        break;
    case GLUT_MIDDLE_BUTTON:
    case GLUT_RIGHT_BUTTON:
        if (state == GLUT_DOWN)
            glutIdleFunc(NULL);
        break;
    default:
        break;
    }
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (400, 400);
    glutInitWindowPosition (100, 100);
    glutCreateWindow (argv[0]);
    init ();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutMainLoop();

    return 0;
}
