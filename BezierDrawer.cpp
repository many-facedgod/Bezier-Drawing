/* 
 * File:   BezierDrawer.cpp
 * Author: tanmaya
 *
 * Created on 20 November, 2017, 3:45 PM
 */

#include "BezierDrawer.h"

BezierDrawer::BezierDrawer(int Steps)
{
    steps = Steps;
    curvePoints.reserve(steps);
}

void BezierDrawer::make(std::vector< Point > ControlPoints)
{
    controlPoints = ControlPoints;
    curvePoints.clear();
    GLdouble incr = 1.0 / steps;    
    for(GLdouble t = 0.0; t <= 1.0; t += incr)
    {    
        curvePoints.push_back(deCasteljau(0, controlPoints.size() - 1, t));
    }
}

void BezierDrawer::add(Point p)
{
    controlPoints.push_back(p);
    GLdouble incr = 1.0 / steps;
    if(controlPoints.size() == 1)
    {
        for(GLdouble t = 0.0; t <= 1.0; t += incr)
        {    
            curvePoints.push_back(p);
        }
        return;
    }
    int i = 0;
    for(GLdouble t = 0.0; t <= 1.0; t += incr)
    {    
        curvePoints[i] = lerp(curvePoints[i], deCasteljau(1, controlPoints.size() - 1, t), t);
        i++;
    }   
}

Point BezierDrawer::lerp(Point p1, Point p2, GLdouble t)
{
    return make_pair(p1.first * (1 - t) + p2.first * t, p1.second * (1 - t) + p2.second * t);
}

Point BezierDrawer::deCasteljau(int start, int end, GLdouble t)
{
    std::vector < Point > temp(controlPoints);
    for(int i = end; i > start; i--)
    {
        for(int j = start; j < i; j++)
            temp[j] = lerp(temp[j], temp[j + 1], t);
    }
    return temp[start];    
}

