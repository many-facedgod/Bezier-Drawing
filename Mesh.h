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

bool operator == (Point a, Point b)
{
    if(a.x == b.x && a.y==b.y && a.z==b.z)
        return true;
    else
        return false;
}
/**
 * Structure which represents a 3D point
 */
struct Point {
    double x,y,z;
};

/**
 * Structure to store the color values of objects
 */
struct Color{
    double r,g,b,a;
};

/**
 * Class to model a polygonal mesh using pointer to vertex list representation
 */
class Mesh {
    vector<Point> vertices; //list of vertices
    vector<vector<long> > polygons; //list of polygons
    vector<Color> vertexColors;
    vector<Color> polygonColors;

public:
    /**
     * Function to add a 3D point to the mesh
     * @param p point to be added
     * @param c color of the point
     */
    inline void addPoint(Point p, Color c = {255,255,255}) {
        vertices.push_back(p);
    }

    /**
     * Function to add a polygon to the mesh
     * @param polygon set of vertices in anticlockwise order which define the polygon
     * @param c color of the polygon
     */
    inline void addPolygon(vector<long> polygon, Color c = {255,255,255}) {
        polygons.push_back(polygon);
    }

    /**
     * Fetch the vertex list of the input polygon
     */
    vector<long> getVertexListOfPolygon(long polygonNumber) {
        if(polygonNumber>=polygons.size())
        {
            vector<long> temp;
            return temp;
        }
        else
            return polygons[polygonNumber];
    }

    /**
     * Fetch the coordinates of input point
     */
    Point getVertexCoordinates(long vertexNumber){
        if(vertexNumber>=vertices.size())
        {
            Point temp;
            return temp;
        }
        else
            return vertices[vertexNumber];
    }

    /**
     * Returns the vertex number of the input point
     */
    long getVertexIndex(Point p) {
        if (find(vertices.begin(), vertices.end(), p) != vertices.end())
            return
        else
            return -1;
    }

    /**
     * Serialize the mesh in OFF format
     * @param filename name of the OFF file
     */
    void serialize(string filename)
    {
        fstream f(filename,ios::out);
        f<<"OFF"<<endl;
        f<<vertices.size()<<" "<<polygons.size()<<endl;
    }

};

#endif //BEZIER_DRAWING_MESH_H
