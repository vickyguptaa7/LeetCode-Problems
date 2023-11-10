class Solution {
public:
    
    void helper(int src,int par,map<int,vector<int>>&list,vector<int>&nums)
    {
        nums.push_back(src);
        for(auto child:list[src])
        {
            if(child==par)continue;
            helper(child,src,list,nums);
        }
    }
    
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n=adjacentPairs.size();
        map<int,vector<int>>list;
        map<int,int>inorder;
        for(auto edge:adjacentPairs)
        {
            list[edge[0]].push_back(edge[1]);
            list[edge[1]].push_back(edge[0]);
            inorder[edge[1]]++;
            inorder[edge[0]]++;
        }
        int src=0;
        for(auto x:inorder)
        {
            if(x.second==1)
            {
                src=x.first;
                break;
            }
        }
        vector<int>nums;
        helper(src,-1e6,list,nums);
        return nums;
    }
};