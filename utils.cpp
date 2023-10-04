#include "utils.h"

using namespace std;


bool isConvex(Polygon& polygon) {
    for(int i=0;i<polygon.edges.size()-1;++i){
        if(vectorCross(polygon.edges[i], polygon.edges[i+1])<0)  return false;
    }
    return true;
}

PostionState getEdgePositionState(Edge& splitLine, Edge& edge, Edge& subPos, Edge& subNeg){
    Edge normal=Edge({0,0}, { -splitLine.val.second, splitLine.val.first });
    Edge u=Edge({splitLine.v0.first, splitLine.v0.second}, {edge.v0.first, edge.v0.second});
    Edge w=Edge({splitLine.v0.first, splitLine.v0.second}, {edge.v1.first, edge.v1.second});
    double d0=vectorDot(normal, u);
    double d1=vectorDot(normal, w);
    if(d0*d1<0) {
        double t=d0/(d0-d1);
        pair<double, double> I= {edge.v0.first+ t*(edge.v1.first-edge.v0.first), edge.v0.second+ t*(edge.v1.second-edge.v0.second)};
        if(d1>0){
            subNeg=Edge(edge.v0, I);
            subPos=Edge(I, edge.v1);
        }else{
            subPos=Edge(edge.v0, I);
            subNeg=Edge(I, edge.v1);
        }
        return CROSSES;
    }else if(d0>0 || d1>0){
        return POSITIVE;
    }else if(d0<0 || d1<0){ 
        return NEGATIVE;
    }else return COINCIDENT;
}

PostionState getPointPositionState(Edge& splitLine, pair<double, double>& point){
    Edge normal=Edge({0,0}, { -splitLine.val.second, splitLine.val.first });
    Edge u=Edge({splitLine.v0.first, splitLine.v0.second}, {point.first, point.second});
    double d=vectorDot(normal, u);
    if(d>0) {
        return POSITIVE;
    }else if(d<0){
        return NEGATIVE;
    }else return COINCIDENT;
}

