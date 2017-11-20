/* 
 * File:   main.cpp
 * Author: tanmaya
 *
 * Created on 20 November, 2017, 2:11 PM
 */

#include <cstdlib>
#include "Camera.h"
#include "BezierDrawer.h"

using namespace std;
/*
 * Utils
 */
Camera* C;
BezierDrawer* B;

/*
 * Params
 */
int width = 500;
int height = 500;
GLdouble curveColor[3] = {1.0, 0.0, 0.0};
GLdouble controlColor[3] = {0.0, 0.0, 1.0};
GLdouble backColor[3] = {0.0, 0.0, 0.0};

/**
 * The rendering function
 */
void draw()
{
    
    glClear  (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_LINE_STRIP);
        glColor3d(controlColor[0], controlColor[1], controlColor[2]);
        for (auto point: B->controlPoints)
            glVertex2d(point.first, point.second);
    glEnd();
    glBegin(GL_LINE_STRIP);    
        glColor3d(curveColor[0], curveColor[1], curveColor[2]);
        for (auto point: B->curvePoints)
            glVertex2d(point.first, point.second);
    glEnd();    
    glutSwapBuffers();
}

/**
 * Initializes the glut parameters and the GL camera
 */
void initGlut()
{
    int x = 0;
    glutInit(&x, nullptr);    
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(width, height);
    glutCreateWindow("Bezier");
    C = new Camera(width, height);
    glClearColor(backColor[0], backColor[1], backColor[2], 0);
}

int main(int argc, char** argv)
{   
    initGlut();
    B = new BezierDrawer(100);
    std::vector < pair<GLdouble, GLdouble> > controls;
    controls.push_back(make_pair(0.0, 0.0));
    controls.push_back(make_pair(110.0, 110.0));
    controls.push_back(make_pair(20.0, 70.0));
    controls.push_back(make_pair(50.0, 27.0));
    B->make(controls);    
    glutDisplayFunc(draw);
    glutMainLoop();
}

