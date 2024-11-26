class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>inorder(n,0);
        for(auto edge:edges)
        {
            inorder[edge[1]]++;
        }
        int res=-1;
        for(int i=0;i<n;i++)
        {
            if(inorder[i]==0)
            {
                if(res!=-1)
                    return -1;
                else res=i;
            }
        }
        return res;
    }
};