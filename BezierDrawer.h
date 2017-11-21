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
typedef std::pair<GLdouble, GLdouble> Point;
class BezierDrawer
{
public:
    int steps;
    std::vector < Point > controlPoints;
    std::vector < Point > curvePoints;
    BezierDrawer(int Steps);
    void makeFromVector (std::vector < Point > ControlPoints);
    void make();
    void add (Point p);
    void deleteControl(int index);
private:
    Point lerp(Point p1, Point p2, GLdouble t);
    Point deCasteljau(int start, int end, GLdouble t);
    
};

#endif /* BEZIERDRAWER_H */

