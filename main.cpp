// author: yudong.lin 2023.09.26

#include "DotMatrix.h"
#include "Polygon.h"
#include "utils.h"
#include "iostream"

#define N 100

using namespace std;

void lightDots(Polygon& polygon, DotMatrix& dotMatrix){
    cout<<"cur polygon is "<<(isConvex(polygon)?"convex.":"concave.")<<endl;
    cout<<endl;
    dotMatrix.drawPolygon(polygon);
    dotMatrix.show();
    dotMatrix.clear();
    cout<<endl;
    return;
}

// Readme.md 有详细的可视化

int main(){
    DotMatrix dotMatrix(N);

    vector<pair<double,double>> concaveDots{{20,40}, {40,40}, {50,10}, {70,40}, {50,70}}; // 凹多边形
    Polygon concavePolygon(concaveDots);
    lightDots(concavePolygon, dotMatrix);

    vector<pair<double,double>> convexDots{{60,90}, {40,70}, {40,45}, {50,25}, {65,20}, {90,70}}; // 凸多边形
    Polygon convexPolygon(convexDots);
    lightDots(convexPolygon, dotMatrix);

    vector<pair<double,double>> concaveDots1{{20,40}, {40,50}, {50,10}, {70,40}, {50,70}}; // 分割线有Cross的凹多边形
    Polygon concavePolygon1(concaveDots1);
    lightDots(concavePolygon1, dotMatrix);

    return 0;
}