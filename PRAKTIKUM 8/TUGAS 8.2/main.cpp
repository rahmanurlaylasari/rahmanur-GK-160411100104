#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

static GLfloat spin = 0.0;
static int xx, yy, z=1;
bool jalan = false;

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotatef(spin, xx, yy, z);
    glColor3f(1.0, 1.0, 1.0);
    glRectf(-25.0, -25.0, 25.0, 25.0);
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

void reshape(int w, int h)
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void mouse(int button, int state, int x, int y) {
    switch (button) {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN){
            xx = 0;
            yy = 0;
            z = 1;
        }
        break;
    case GLUT_MIDDLE_BUTTON:
        if (state == GLUT_DOWN){
            xx = 0;
            yy = 1;
            z = 0;
        }
        break;
    case GLUT_RIGHT_BUTTON:
        if (state == GLUT_DOWN){
            xx = 1;
            yy = 0;
            z = 0;
        }
        break;
    default:
        break;
    }
}

void input(unsigned char key, int x, int y){
    switch(key) {
    case 'P':
    case 'p':
        if (jalan==false){
            jalan = true;
            glutIdleFunc(spinDisplay);
        } else {
            jalan = false;
            glutIdleFunc(NULL);
        }
    }
}
int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (400, 400);
    glutInitWindowPosition (100, 100);
    glutCreateWindow (argv[0]);
    init ();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(input);
    glutMouseFunc(mouse);
    glutMainLoop();

    return 0;
}
