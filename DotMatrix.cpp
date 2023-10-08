#include "DotMatrix.h"
#include "BSP.h"
#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

void DotMatrix::show(){
    for(int i=0;i<size;++i){
        for(int j=0;j<size;++j){
            cout<<dots[i][j];
        }
        cout<<endl;
    }
    return;
}

void  DotMatrix::clear(){
    dots=vector<std::vector<int>>(size, std::vector<int>(size, 0));
    return;
}


void  DotMatrix::drawPolygon(Polygon& polygon){
    int row=0, col=0;
    for(int i=0;i<polygon.vertexSize;++i){
        auto& elem=polygon.dots[i];
        row=elem.first;
        col=elem.second;
        dots[size-1-col][row]=1;
    }
    BSP bsp(polygon);
    for(int i=0;i<size;++i){
        for(int j=0;j<size;++j){
            col=size-1-i;
            row=j;
            if(bsp.getPointLocation(bsp.getRoot(), row, col)>=0)
                dots[size-1-col][row]=1;
        }
    }
    return;
}
