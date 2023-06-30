#define GL_SILENCE_DEPRECATION
#include <math.h>


#if __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#elif _WIN64
#include <GL/glut.h>
#endif

void display(void) {
// clear background of current window
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
// To operate on model-view matrix
    glMatrixMode(GL_MODELVIEW);

// draw a filled triangle
    glLoadIdentity();
    gluOrtho2D(0, 350.0, 0, 150.0);

    glBegin(GL_TRIANGLES);

    glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex2i(75, 85);
    glVertex2i(20, 40);
    glVertex2i(130, 40);

    glEnd();

// draw a filled polygon
    glLoadIdentity();
    gluOrtho2D(290.0, 0, 0, 150.0);

    glBegin(GL_POLYGON);

    glColor3f(1.0f, 0.0f, 0.0f); // red
    for(int degAngle = 0; degAngle <= 360; degAngle++){
        double x = 50 * cos((degAngle * 3.14159265359) / 180) + 75;
        double y = 50 * sin((degAngle * 3.14159265359) / 180) + 75;
        glVertex2i(x, y);
    }

    glEnd();
    glFlush();
}

void init(void) {
    //Clear background color to white
    glClearColor(0.0, 0.0, 0.0, 0.0);

    //change projection mode
    glMatrixMode(GL_PROJECTION);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}



int main(int argc, char **argv) {

    glutInit(&argc, argv);
    glutInitWindowSize(1000, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Triangle & Circle");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;

}
