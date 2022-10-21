
typedef pair<int,pair<int,int>> ppi; 

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<ppi,vector<ppi>,greater<ppi>>pque;
        int n=matrix.size();
        for(int i=0;i<n;i++)
        {
            pque.push({matrix[i][0],{i,0}});
        }
        k--;
        while(k)
        {
            auto curr=pque.top();
            int _x=curr.second.first;
            int _y=curr.second.second;
            pque.pop();
            if(_y!=n-1)
            {
                pque.push({matrix[_x][_y+1],{_x,_y+1}});
            }
            k--;
        }
        return pque.top().first;
    }
};