//
// Created by kartik on 21/11/17.
//

#ifndef BEZIER_DRAWING_SURFACEOFREVOLUTION_H
#define BEZIER_DRAWING_SURFACEOFREVOLUTION_H

#include "BezierDrawer.h"
#include "Mesh.h"
#include <bits/stdc++.h>

void meshInit(BezierDrawer* B, vector<vector<dvec3> > &vertices)
{
    vector<dvec3> temp;
    for(auto point: B->curvePoints)
    {
        dvec3 p1 = {point.first, point.second, 0};
        temp.push_back(p1);
    }
    vertices.push_back(temp);
}

void getRotateMat(dmat3 &rotate_mat, double angle)
{
    rotate_mat[0][0] = cos(radians(angle));
    rotate_mat[0][1] = 0.0;
    rotate_mat[0][2] = sin(radians(angle));
    rotate_mat[1][0] = 0.0;
    rotate_mat[1][1] = 1.0;
    rotate_mat[1][2] = 0.0;
    rotate_mat[2][0] = -sin(radians(angle));
    rotate_mat[2][1] = 0.0;
    rotate_mat[2][2] = cos(radians(angle));
}

void updateVertices(vector<vector<dvec3> > &vertices, dmat3 rotate_mat)
{
    long size = vertices.size();
    vector<dvec3> new_points;
    vector<dvec3> previous_points (vertices[size-1].begin(), vertices[size-1].end());
    for(auto point: previous_points)
    {
        dvec3 temp_point = dvec3(point.x, point.y, point.z);
        dvec3 transformed_point = rotate_mat * temp_point;
        dvec3 trans_point = {transformed_point[0], transformed_point[1], transformed_point[2]};
        new_points.push_back(trans_point);
    }
    vertices.push_back(new_points);
}

void makeMesh(vector<vector<dvec3> > &vertices, double increment)
{
    // Iterating over degree from 1 to 360
    for(double angle = increment; angle < 360; angle+= increment)
    {
        dmat3 rotate_mat(0.0f);
        getRotateMat(rotate_mat, angle);
        updateVertices(vertices, rotate_mat);

    }
    
}

#endif //BEZIER_DRAWING_SURFACEOFREVOLUTION_H

