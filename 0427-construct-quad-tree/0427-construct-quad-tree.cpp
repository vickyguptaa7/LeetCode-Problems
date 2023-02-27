/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    
    Node* helper(int sx,int sy,int len,vector<vector<int>>&grid)
    {
        int cntr=0;
        for(int i=sx;i<sx+len;i++)
        {
            for(int j=sy;j<sy+len;j++)
            {
                cntr+=grid[i][j];
            }
        }
        if(cntr==0)
        {
            return new Node(0,1);
        }
        if(cntr==len*len)
        {
            return new Node(1,1);
        }
        
        Node *topLeft=helper(sx,sy,len/2,grid);
        
        Node *topRight=helper(sx,sy+len/2,len/2,grid);
        
        Node *bottomLeft=helper(sx+len/2,sy,len/2,grid);
        
        Node *bottomRight=helper(sx+len/2,sy+len/2,len/2,grid);
        
        return new Node(0,0,topLeft,topRight,bottomLeft,bottomRight);
    }
    
    Node* construct(vector<vector<int>>& grid) {
        int n=grid.size();
        return helper(0,0,n,grid);
    }
};