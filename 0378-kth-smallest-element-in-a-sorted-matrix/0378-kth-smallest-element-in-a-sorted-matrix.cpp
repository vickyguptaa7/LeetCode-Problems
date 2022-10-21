class Solution {
public:
    
    int isValidCount(vector<vector<int>>& matrix, int value)
    {
        int cnt=0;
        for(auto x:matrix)
        {
            for(auto y:x)
            {
                if(y>value)
                    break;
                cnt++;
            }
        }
        return cnt;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int low=matrix[0][0],high=matrix[n-1][n-1];
        int ans=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(isValidCount(matrix,mid)>=k)
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};



// typedef pair<int,pair<int,int>> ppi; 

// class Solution {
// public:
//     int kthSmallest(vector<vector<int>>& matrix, int k) {
//         priority_queue<ppi,vector<ppi>,greater<ppi>>pque;
//         int n=matrix.size();
//         for(int i=0;i<n;i++)
//         {
//             pque.push({matrix[i][0],{i,0}});
//         }
//         k--;
//         while(k)
//         {
//             auto curr=pque.top();
//             int _x=curr.second.first;
//             int _y=curr.second.second;
//             pque.pop();
//             if(_y!=n-1)
//             {
//                 pque.push({matrix[_x][_y+1],{_x,_y+1}});
//             }
//             k--;
//         }
//         return pque.top().first;
//     }
// };