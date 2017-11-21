/* 
 * File:   BezierDrawer.h
 * Author: tanmaya
 *
 * Created on 20 November, 2017, 3:45 PM
 */

#ifndef BEZIERDRAWER_H
#define BEZIERDRAWER_H
#include <unordered_map>
#include <vector>
#include "Camera.h"
typedef std::pair<GLdouble, GLdouble> Point2d;
class BezierDrawer
{
public:
    int steps;
    std::vector < Point2d > controlPoints;
    std::vector < Point2d > curvePoints;
    BezierDrawer(int Steps);
    void make (std::vector < Point2d > ControlPoints);
    void add (Point2d p);
private:
    Point2d lerp(Point2d p1, Point2d p2, GLdouble t);
    Point2d deCasteljau(int start, int end, GLdouble t);
    
};

#endif /* BEZIERDRAWER_H */

