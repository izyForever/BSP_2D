#pragma once
#include <vector>

class Edge{
    public:
    Edge(){};
    Edge(std::pair<double, double>& v0, std::pair<double, double>& v1): v0(v0), v1(v1){
        val=std::pair<double, double>(v1.first-v0.first, v1.second-v0.second);
    }

    Edge(std::pair<double, double>&& v0, std::pair<double, double>&& v1): v0(v0), v1(v1){
        val=std::pair<double, double>(v1.first-v0.first, v1.second-v0.second);
    }
    std::pair<double, double> v0;
    std::pair<double, double> v1;
    std::pair<double, double> val;
    std::pair<int, int> indexes; //表示多边形vertex的逆时针次序，用于凸包BSP的二分分割线建立
};

class Polygon {
    public: 
        Polygon(std::vector<std::pair<double,double>>& dots); //多边形点集逆时针表示
        std::vector<std::pair<double,double>> dots;
        std::vector<Edge> edges;
        int vertexSize;
};

