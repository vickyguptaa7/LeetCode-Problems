class Solution {
public:
    vector<vector<int>>result;
    vector<int>value={1,2,3,4,5,6,7,8,9};
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>dp;
        vector<int>ans;
        helper(0,n,k,ans);
        return result;
    }
    void helper(int s,int n,int k,vector<int>ans)
    {
        if(k<=0||n<=0||s>=9)
        {
            if(n==0&&k==0){
             result.push_back(ans);
            }
            return;
        }
        
        if(n>=value[s])
        {
            ans.push_back(value[s]);
            helper(s+1,n-value[s],k-1,ans);
            ans.pop_back();
        }
        helper(s+1,n,k,ans);
    }
};