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
Camera* C;
BezierDrawer* B;
/*
 * 
 */

void draw()
{
    
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINE_STRIP);
    glVertex2d(0.1, 0.10);
    for (auto point: B->curvePoints)
    {
        
        glVertex2d(point.first, point.second);
    }
    glEnd();
    glFlush();
}

void initGlut()
{
    int x;
    glutInit(&x, nullptr);    
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Bezier");
    C = new Camera(500, 500);
    glClearColor(0, 0, 0, 0);
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

