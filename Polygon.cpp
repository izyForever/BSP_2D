#include "Polygon.h"
#include <vector>
#include <iostream>
#include <cstdlib>


using namespace std;

Polygon::Polygon(vector<pair<double,double>>& dots){
    if(dots.size()<3) throw runtime_error("invalid number of dots");
    Edge tmp;
    vertexSize=dots.size();
    this->dots=dots;
    for(int i=0;i<dots.size()-1;++i){
        auto& a=dots[i], b=dots[i+1];
        tmp=Edge(a, b);
        tmp.indexes=pair<int,int>(i, i+1);
        edges.push_back(tmp);
    }
    auto& a=dots[dots.size()-1], b=dots[0];
    tmp=Edge(a, b);
    tmp.indexes=pair<int,int>(dots.size()-1, 0);
    edges.push_back(tmp);
    
}