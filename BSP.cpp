#include "BSP.h"
#include "utils.h"
#include <vector>

using namespace std;


BSP::BSP(Polygon& polygon){
    polygonPtr = &polygon;
    root=constructBSP(polygon.edges, height, isConvex(polygon));
    
}

BSP::~BSP(){
    freeBSP(root);
    polygonPtr=nullptr;
}

TreeNode* BSP::constructBSP(vector<Edge> edges, int& height, bool convex){
    if(edges.size()==0) return nullptr;
    TreeNode* root = new TreeNode();
    Edge split;
    ++height;
    if(convex){
        if (edges.size() != 1) {
            int pivot = getMiddleIndex(edges[0].indexes.first, edges[edges.size() - 1].indexes.second, polygonPtr->vertexSize);
            int startIndex = edges[0].indexes.first;
            split = Edge(polygonPtr->dots[startIndex], polygonPtr->dots[pivot]);
        }
        else {
            split = edges[0];
        }
    }
    else{
        split=edges[0];
    }
    root->edge=split;
    Edge subPos, subNeg;
    vector<Edge> posArr, negArr;
    for(int i=0;i<edges.size();++i){
        PostionState state=getEdgePositionState(split, edges[i], subPos, subNeg);
        if(state==PostionState::CROSSES){
            posArr.push_back(subPos);
            negArr.push_back(subNeg);
        }else if(state==PostionState::POSITIVE){
            posArr.push_back(edges[i]);
        }else if(state==PostionState::NEGATIVE){
            negArr.push_back(edges[i]);
        }else{
            root->coincident.push_back(edges[i]);
        }
    }
    if(!posArr.empty()){
        root->left=constructBSP(posArr, height, convex);
    }else {
        root->left=nullptr;
    }
    if(!negArr.empty()){
        root->right=constructBSP(negArr, height, convex);
    }else {
        root->right=nullptr;
    }
    return root;
}

void BSP::freeBSP(TreeNode* root){
    if(root==nullptr) return;
    freeBSP(root->left);
    freeBSP(root->right);
    delete root;
    return;
}



int BSP::getPointLocation(TreeNode* root, int x, int y){
    Edge tmp({0,0}, {x,y});
    pair<double, double> point(x, y);
    PostionState state=getPointPositionState(root->edge, point);
    if(state==PostionState::POSITIVE){
        if(root->left) return getPointLocation(root->left, x, y);
        else return 1; // inside 
    }else if (state==PostionState::NEGATIVE) {
        if(root->right) return getPointLocation(root->right, x, y);
        else return -1; // outside 
    }else{
        for(auto& edge: root->coincident){
            Edge normal=Edge({0,0}, {-edge.val.second, edge.val.first });
            tmp=Edge({edge.v0.first, edge.v0.second}, {x,y});
            if(vectorDot(tmp, normal)==0){
                int xLeft=edge.v0.first, xRight=edge.v1.second,xbak;
                xbak=xLeft;
                xLeft=xLeft<xRight?xLeft:xRight;
                xRight=xRight>xbak?xRight:xbak;
                int yDonw = edge.v0.second, yUp = edge.v1.second, ybak;
                ybak = yDonw;
                yDonw = yDonw <yUp ? yDonw : yUp;
                yUp = yUp > ybak ? yUp : ybak;
                if(xLeft<=x&&x<=xRight&& yDonw <= y && y <= yUp) return 0; // onEdge
            }
        }
        if(root->left) return getPointLocation(root->left, x, y);
        else if(root->right) return getPointLocation(root->right, x, y);
        else{
            return 0;
        }
    }
}