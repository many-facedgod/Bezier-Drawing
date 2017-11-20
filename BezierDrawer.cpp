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
}

void BezierDrawer::make(std::vector<std::pair<GLdouble,GLdouble> > ControlPoints)
{
    controlPoints = ControlPoints;
    curvePoints.clear();
    GLdouble incr = 1.0 / steps;
    for(GLdouble t = 0.0; t <= 1.0; t += incr)
        curvePoints.push_back(deCasteljau(0, controlPoints.size() - 1, t));
}

std::pair<GLdouble, GLdouble> BezierDrawer::deCasteljau(int start, int end, GLdouble t)
{
    if(start == end)
        return controlPoints[start];
    auto p1 = deCasteljau(start, end - 1, t);
    auto p2 = deCasteljau(start + 1, end, t);
    return make_pair(p1.first * (1 - t) + p2.first * t, p1.second * (1 - t) + p2.second * t);
    
}

