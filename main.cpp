/* 
 * File:   main.cpp
 * Author: tanmaya
 *
 * Created on 20 November, 2017, 2:11 PM
 */

#include <cstdlib>
#include "Camera.h"
#include "BezierDrawer.h"
#include "SurfaceOfRevolution.h"
#include "Mesh.h"

using namespace std;
/*
 * Utils
 */
Camera* C;
BezierDrawer* B;

/*
 * Params
 */
int width = 500; //width of the window
int height = 500; //height of the window
GLdouble curveColor[3] = {1.0, 0.0, 0.0}; //color of the Bezier curve
GLdouble controlColor[3] = {0.0, 0.0, 1.0}; //color of the Control polygon
GLdouble backColor[3] = {0.0, 0.0, 0.0}; //color of the background
double clickThresh = 50.0; //threshold for clicking distance
/**
 * The rendering function
 */
void draw()
{
    glClear  (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_LINE_STRIP); //drawing the bounding box
        glColor3d(controlColor[0], controlColor[1], controlColor[2]);
        for (auto point: B->controlPoints)
            glVertex2d(point.first, point.second);
    glEnd();
    glBegin(GL_LINE_STRIP); //drawing the curve
        glColor3d(curveColor[0], curveColor[1], curveColor[2]);
        for (auto point: B->curvePoints)
            glVertex2d(point.first, point.second);
    glEnd();    
    glutSwapBuffers();
}

/**
 * Computes the squared Euclidean distance between two points
 * @param p The first point
 * @param q The second point
 * @return The squared Euclidean distance
 */
double dist(Point p, Point q)
{
    return (p.first - q.first) * (p.first - q.first) + (p.second - q.second) * (p.second - q.second);
}
/**
 * Deletes the closest control point of B to p and remakes the curve
 * @param p The reference point
 */
void deleteClosest(Point p)
{
    double min = std::numeric_limits<double>::max();
    int position = 0;
    for(int i = 0; i < B->controlPoints.size(); i++) //looping to find minimum dist
    {
        double d = dist(B->controlPoints[i], p);
        if(d < min)
        {
            min = d;
            position = i;
        }
    }
    if (min < clickThresh) //checking if it is less than a threshold
        B->deleteControl(position);
}
/**
 * The mouse click callback method
 * @param button The glut enum for left or right button
 * @param state Pressed or released
 * @param x x coordinate on the window
 * @param y y coordinate on the window
 */
void mouseClick(int button, int state, int x, int y)
{
    if(button ==  GLUT_LEFT_BUTTON && state == GLUT_DOWN) //addition
    {
        B->add(make_pair((double)x, height - (double)y));
        vector<vector<dvec3> > vertices;
        meshInit(B, vertices);
        makeMesh(vertices,1);
    }
    else if(button ==  GLUT_RIGHT_BUTTON && state == GLUT_DOWN) //deletion
    {
        deleteClosest(make_pair((double)x, height - (double)y));
    }
    glutPostRedisplay();
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
    B = new BezierDrawer(10);

    glClearColor(backColor[0], backColor[1], backColor[2], 0);
    glutMouseFunc(mouseClick);
}

int main(int argc, char** argv)
{   
    initGlut();
    glutDisplayFunc(draw);
    glutMainLoop();
}

