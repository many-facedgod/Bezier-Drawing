//
// Created by kartik on 21/11/17.
//

#ifndef BEZIER_DRAWING_SURFACEOFREVOLUTION_H
#define BEZIER_DRAWING_SURFACEOFREVOLUTION_H

#endif //BEZIER_DRAWING_SURFACEOFREVOLUTION_H

#include "BezierDrawer.h"
#include "Mesh.h"

void surfaceInit(BezierDrawer* B, vector<vector<Point> > vertices)
{
    for(auto point: B->curvePoints)
    {
        Point p1;
        p1.x = point.first;
        p1.y = point.second;
        p1.z = 0;
        vertices[0].push_back(p1);
    }
}


void makeSurface(BezierDrawer* B)
{
    for(auto point: B->curvePoints)
    {
        cout<<point.first<<" "<<point.second<<endl;
    }
}