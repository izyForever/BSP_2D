#pragma once
#include "Polygon.h"
#include <vector>
#include <unordered_set>

class TreeNode{
    public:
      TreeNode(){};
      TreeNode* left;
      TreeNode* right;
      Edge edge;
      std::vector<Edge> coincident;
};



class BSP{
    public:
        BSP(Polygon& polygon);
        BSP(BSP& bsp)=delete;
        ~BSP();
        BSP& operator=(BSP& bsp)=delete;
        TreeNode* travalToLeaf(int x, int y);
        bool isInterior(int x, int y);
        int getPointLocation(TreeNode* root, int x, int y);
        inline TreeNode* getRoot(){return root;}
    private:
        TreeNode* root;
        Polygon* polygonPtr;
        int height;
        TreeNode* constructBSP(std::vector<Edge> edges, int& height, bool convex);
        void freeBSP(TreeNode* root);
};