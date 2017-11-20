/* 
 * File:   BezierDrawer.h
 * Author: tanmaya
 *
 * Created on 20 November, 2017, 3:45 PM
 */

#ifndef BEZIERDRAWER_H
#define BEZIERDRAWER_H
#include <vector>
#include "Camera.h"
class BezierDrawer
{
public:
    int steps;
    std::vector < std::pair<GLdouble, GLdouble> > controlPoints;
    std::vector < std::pair<GLdouble, GLdouble> > curvePoints;
    BezierDrawer(int Steps);
    void make (std::vector < std::pair<GLdouble, GLdouble> > ControlPoints);
private:
    std::pair<GLdouble, GLdouble> deCasteljau(int start, int end, GLdouble t);
    
};

#endif /* BEZIERDRAWER_H */

