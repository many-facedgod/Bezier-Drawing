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
struct Point {
    double x;
    double y;
    double z;
};

/**
 * Class to model a polygonal mesh using pointer to vertex list representation
 */
class Mesh {
    vector<Point> vertices; //list of vertices
    vector<vector<long> > polygons; //list of polygons

public:
    /**
     * Function to add a 3D point to the mesh
     * @param p point to be added
     */
    inline void addPoint(Point p) {
        vertices.push_back(p);
    }

    /**
     * Function to add a polygon to the mesh
     * @param polygon set of vertices in anticlockwise order which define the polygon
     */
    inline void addPolygon(vector<long> polygon) {
        polygons.push_back(polygon);
    }

    /**
     * Fetch the vertex list of the input polygon
     */
    vector<long> getVertexListOfPolygon(long polygonNumber) {
        if(polygonNumber>=polygons.size())
            return NULL;
        else
            return polygons[polygonNumber];
    }

    /**
     * Fetch the coordinates of input point
     */
    Point getVertexCoordinates(long vertexNumber){
        if(vertexNumber>=vertices.size())
            return NULL;
        else
            return vertices[vertexNumber];
    }

    /**
     * Returns the vertex number of the input point
     */
    long getVertexIndex(Point p) {
        if (find(vertices.begin(), vertices.end(), p) == vertices.end())
            return -1;
        else
            return find(vertices.begin(), vertices.end(), p) - vertices.begin();
    }
};

#endif //BEZIER_DRAWING_MESH_H
