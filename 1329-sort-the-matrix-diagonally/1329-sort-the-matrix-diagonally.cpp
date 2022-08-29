class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int rows=mat.size(),cols=mat[0].size();
        vector<vector<int>> res(rows,vector<int>(cols,0));
        
        priority_queue<int,vector<int>,greater<int>>pque;
        for(int i=rows-1;i>0;i--)
        {
            int r=i,c=0;
            while(r<rows&&c<cols)
            {
                pque.push(mat[r][c]);
                r++;c++;
            }
            r=i,c=0;
            while(r<rows&&c<cols)
            {
                res[r][c]=pque.top();
                pque.pop();
                r++;
                c++;
            }
        }
        for(int i=0;i<cols;i++)
        {
            int r=0,c=i;
            while(r<rows&&c<cols)
            {
                pque.push(mat[r][c]);
                r++;c++;
            }
            r=0,c=i;
            while(r<rows&&c<cols)
            {
                res[r][c]=pque.top();
                pque.pop();
                r++;
                c++;
            }
        }
        return res;
    }
};