#pragma once
#include <vector>
#include "Polygon.h"

class DotMatrix {
    public: 
        DotMatrix(int n): size(n), dots(n, std::vector<int>(n,0)){};
        void show();
        inline void clear() {dots=std::vector<std::vector<int>>(size, std::vector<int>(size, 0));}
        void drawPolygon(Polygon& polygon);
    private:
        int size;
        std::vector<std::vector<int>> dots;
};

