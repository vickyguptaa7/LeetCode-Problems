class Solution {
public:
    
    void helper(int ele,int n,int k,vector<int>&curr,vector<vector<int>>&combinations)
    {
        if(ele>n)
        {
            if(k>0)
                return;
            combinations.push_back(curr);
            return;
        }
        helper(ele+1,n,k,curr,combinations);
        if(k==0)return;
        curr.push_back(ele);
        helper(ele+1,n,k-1,curr,combinations);
        curr.pop_back();
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>combinations;
        vector<int>curr;
        helper(1,n,k,curr,combinations);
        return combinations;
    }
};