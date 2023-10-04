#pragma once
#include "Polygon.h"

enum PostionState{
    CROSSES,
    POSITIVE,
    NEGATIVE,
    COINCIDENT
};

inline double vectorCross(Edge& p1, Edge& p2){
    return p1.val.first*p2.val.second-p1.val.second*p2.val.first;
}

inline double vectorDot(Edge& p1, Edge& p2){
    return p1.val.first*p2.val.first+p1.val.second*p2.val.second;
}

PostionState getEdgePositionState(Edge& splitLine, Edge& edge, Edge& subPos, Edge& subNeg);

PostionState getPointPositionState(Edge& splitLine, std::pair<double, double>& point);

bool isConvex(Polygon& polygon);

inline int getMiddleIndex(int i0, int i1, int N){
    if(i0<i1) return (i0+i1)/2;
    else return ((i0+i1+N)/2)%N;
}