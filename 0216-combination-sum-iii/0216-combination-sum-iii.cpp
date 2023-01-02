class Solution {
public:

    void helper(int num,int k,int n,vector<int>currCombination,
               vector<vector<int>>&allCombination)
    {
        if(n==0&&k==0)
        {
            allCombination.push_back(currCombination);
            return;
        }
        if(num>9)
        {
            return;
        }
        if(n-num>=0)
        {
            helper(num+1,k,n,currCombination,allCombination);
            currCombination.push_back(num);
            helper(num+1,k-1,n-num,currCombination,allCombination);
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>allCombination;
        vector<int>currCombination;
        helper(1,k,n,currCombination,allCombination);
        return allCombination;
    }
};