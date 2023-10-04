#pragma once
#include <vector>
#include "Polygon.h"

class DotMatrix {
    public: 
        DotMatrix(int n): size(n), dots(n, std::vector<int>(n,0)){};
        void show();
        void clear();
        void drawPolygon(Polygon& polygon);
    private:
        int size;
        std::vector<std::vector<int>> dots;
};

