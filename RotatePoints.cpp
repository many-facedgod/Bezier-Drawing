//
// Created by kartik on 20/11/17.
//

#include <bits/stdc++.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include "BezierDrawer.h

void make (std::vector < std::pair<GLdouble, GLdouble> > ControlPoints)
{
    controlPoints = ControlPoints;
    curvePoints.clear();
    GLdouble incr = 1.0 / steps;
    for(GLdouble t = 0.0; t <= 1.0; t += incr)
        curvePoints.push_back(deCasteljau(0, controlPoints.size() - 1, t));
}
