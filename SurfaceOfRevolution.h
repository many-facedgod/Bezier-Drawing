//
// Created by kartik on 21/11/17.
//

#ifndef BEZIER_DRAWING_SURFACEOFREVOLUTION_H
#define BEZIER_DRAWING_SURFACEOFREVOLUTION_H

#endif //BEZIER_DRAWING_SURFACEOFREVOLUTION_H

#include "BezierDrawer.h"
#include "Mesh.h"
#include <bits/stdc++.h>

void surfaceInit(BezierDrawer* B, vector<vector<Point3d> > &vertices)
{
    vector<Point3d> temp;
    for(auto point: B->curvePoints)
    {
        Point3d p1;
        p1.x = point.first;
        p1.y = point.second;
        p1.z = 0;
        temp.push_back(p1);
    }

    vertices.push_back(temp);
}

//void Camera:: yaw(double angle)
//{
//    dmat3 yaw_matrix(0.0f);
//    yaw_matrix[0][0] = cos(radians(angle));
//    yaw_matrix[0][1] = sin(radians(angle));
//    yaw_matrix[1][0] = -sin(radians(angle));
//    yaw_matrix[1][1] = cos(radians(angle));
//
//    dmat3 original_matrix(0.0f);
//    original_matrix[0] = u;
//    original_matrix[1] = n;
//
//    dmat3 transformed_matrix = original_matrix*yaw_matrix;
//    u = transformed_matrix[0];
//    n = transformed_matrix[1];
//
//    setModelViewMatrix();
//}

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

void makeSurface(vector<vector<Point3d> > &vect)
{

    // Iterating over degree from 1 to 360
    for(int angle = 1; angle <= 360; angle++)
    {
        dmat3 rotate_mat(0.0f);
        getRotateMat(rotate_mat, angle);
        int size = vect.size();
        vector<Point3d> temp (vect[size-1].begin(), vect[size-1].end());
        for(auto point: temp)
        {
            dvec3 temp_point = dvec3(point.x, point.y, point.z);

        }


    }



}