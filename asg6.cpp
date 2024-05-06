#include <iostream>
#include <GL/glut.h>
#include <cmath>
using namespace std;

static int submenu,mainmenu;
float x1 ,y1 ,x2 ,y2 ,x3 ,y3;

void myInit()
{
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1000,1000,-1000,1000);
}

void display()
{
    glBegin(GL_LINES);
    glVertex2d(1000,0);
    glVertex2d(-1000,0);
    glVertex2d(0,1000);
    glVertex2d(0,-1000);
    glEnd();
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2d(x1,y1);
    glVertex2d(x2,y2);
    glVertex2d(x3,y3);
    glEnd();
    glFlush();
}

void translation()
{
    float tx = 50;
    float ty = 70;

    float xx1 = x1 + tx;
    float xx2 = x2 + tx;
    float xx3 = x3 + tx;

    float yy1 = y1 + ty;
    float yy2 = y2 + ty;
    float yy3 = y3 + ty;

    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2d(xx1 ,yy1);
    glVertex2d(xx2 ,yy2);
    glVertex2d(xx3 ,yy3);
    glEnd();
    glFlush();
}

void rotation()
{
    float A = 45;

    float xx1 = x1* cos(A) - y1*sin(A);
    float xx2 = x2* cos(A) - y2*sin(A);
    float xx3 = x3* cos(A) - y3*sin(A);

    float yy1 = x1* sin(A) + y1*cos(A);
    float yy2 = x2* sin(A) + y2*cos(A);
    float yy3 = x3* sin(A) + y3*cos(A); 

    glColor3f(0.0, 1.0, 1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2d(xx1 ,yy1);
    glVertex2d(xx2 ,yy2);
    glVertex2d(xx3 ,yy3);
    glEnd();
    glFlush();
}

void reflection()
{
    float xx1 = -x1;
    float xx2 = -x2;
    float xx3 = -x3;

    float yy1 = -y1;
    float yy2 = -y2;
    float yy3 = -y3; 

    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2d(xx1 ,yy1);
    glVertex2d(xx2 ,yy2);
    glVertex2d(xx3 ,yy3);
    glEnd();
    glFlush();
}

void shearing()
{
    float shx, shy;
    shx = 0.5;
    shy = 0.5;
    float xx1 = abs(x1 + shx * y1);
    float xx2 = abs(x2 + shx * y2);
    float xx3 = abs(x3 + shx * y3);

    float yy1 = abs(y1 + shy * x1);
    float yy2 = abs(y2 + shy * x2);
    float yy3 = abs(y3 + shy * x3);

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2d(xx1 ,yy1);
    glVertex2d(xx2 ,yy2);
    glVertex2d(xx3 ,yy3);
    glEnd();
    glFlush();
}

void scaling()
{
    float sx = 1.5;
    float sy = 2;

    float xx1 = x1 * sx;
    float xx2 = x2 * sx;
    float xx3 = x3 * sx;

    float yy1 = y1 * sy;
    float yy2 = y2 * sy;
    float yy3 = y3 * sy;

    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2d(xx1 ,yy1);
    glVertex2d(xx2 ,yy2);
    glVertex2d(xx3 ,yy3);
    glEnd();
    glFlush();
}

void menu(int x)
{
    switch(x)
    {
        case 1 : 
            translation();
            break;
        case 2 :
            rotation();
            break;
        case 3 :
            reflection();
            break;
        case 4 :
            shearing();
            break;
        case 5 :
            scaling();
            break;
    }
}

int main(int argc,char *argv[])
{
    x1 = 0;
    y1 = 0;

    x2 = 400;
    y2 = 0;

    x3 = 200;
    y3 = 400;

    glutInit(&argc, argv);               //initialising glut with our arguments
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);    //our window is a single window and can have colors
    glutInitWindowSize(1000,1000);      //the window size
    glutInitWindowPosition(0,0);        //window appears on top left corner of screen
    glutCreateWindow("2D Transformations");     //give window a name
    myInit();
    glutDisplayFunc(display);

    mainmenu = glutCreateMenu(menu);
    glutAddMenuEntry("----MENU----",0);
    glutAddMenuEntry("Translation",1);
    glutAddMenuEntry("Rotation",2);
    glutAddMenuEntry("Reflection",3);
    glutAddMenuEntry("Shearing",4);
    glutAddMenuEntry("Scaling",5);
    glutAttachMenu(GLUT_RIGHT_BUTTON);    // Attaching menu to right click

    glutMainLoop();     //keep main loop running until terminated
}