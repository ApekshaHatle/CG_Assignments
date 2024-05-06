#include <GL/glut.h>
#include <iostream>

int menuID;
int submenuID;

// Variables for Koch curve
int kochLevel = 0;

void drawKochCurve(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, int level) {
    if (level == 0) {
        glBegin(GL_LINES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glEnd();
    } else {
        GLfloat deltaX = x2 - x1;
        GLfloat deltaY = y2 - y1;
        GLfloat x3 = x1 + deltaX / 3;
        GLfloat y3 = y1 + deltaY / 3;
        GLfloat x4 = x1 + 2 * deltaX / 3;
        GLfloat y4 = y1 + 2 * deltaY / 3;
        GLfloat x5 = x3 + (x4 - x3) * 0.5 - (y4 - y3) * 0.866;
        GLfloat y5 = y3 + (y4 - y3) * 0.5 + (x4 - x3) * 0.866;

        drawKochCurve(x1, y1, x3, y3, level - 1);
        drawKochCurve(x3, y3, x5, y5, level - 1);
        drawKochCurve(x5, y5, x4, y4, level - 1);
        drawKochCurve(x4, y4, x2, y2, level - 1);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw Koch curve
    glColor3f(1.0f, 0.0f, 0.0f);
    drawKochCurve(-0.8f, -0.5f, 0.8f, -0.5f, kochLevel);

    glFlush();
}

void processMenuEvents(int option) {
    switch (option) {
        case 1:
            kochLevel++;
            break;
        case 2:
            kochLevel--;
            if (kochLevel < 0) {
                kochLevel = 0;
            }
            break;
        case 5:
            exit(0);
    }
    glutPostRedisplay();
}

void createMenu() {
    menuID = glutCreateMenu(processMenuEvents);
    glutAddMenuEntry("Increase Level", 1);
    glutAddMenuEntry("Decrease Level", 2);
    glutAddMenuEntry("Exit", 5);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Koch Curve");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutDisplayFunc(display);
    createMenu();

    glutMainLoop();

    return 0;
}