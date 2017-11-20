//
// Created by anikethjr on 20/11/17.
//

#ifndef BEZIER_DRAWING_MESH_H
#define BEZIER_DRAWING_MESH_H

#include <bits/stdc++.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/rotate_vector.hpp>

using namespace std;
using namespace glm;

/**
 * Structure which represents a 3D point
 */
struct Point{
    double x;
    double y;
    double z;
};

/**
 * Class to model a polygonal mesh using pointer to vertex list representation
 */
class Mesh
{
    vector<Point> vertices; //list of vertices
    vector<vector<int> > polygons; //list of polygons

    /**
     * Function to add a 3D point to the mesh
     * @param p point to be added
     */
    void addPoint(Point p)
    {
        vertices.push_back(p);
    }

    /**
     * Function to add a polygon to the mesh
     * @param polygon set of vertices in anticlockwise order which define the polygon
     */
    void addPolygon(vector<int> polygon)
    {
        polygons.push_back(polygon);
    }
};
#endif //BEZIER_DRAWING_MESH_H
