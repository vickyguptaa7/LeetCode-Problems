class Solution {
public:
    void dfs(int src,vector<int>&nums,vector<int>&isVisited,int &ans)
    {
        if(isVisited[src]==0){
        isVisited[src]=true;
        ans++;    
            dfs(nums[src],nums,isVisited,ans);
        }
       
    }
    int arrayNesting(vector<int>& nums) {
        int n=nums.size();
        int result=0;
            vector<int>isVisited(n,0);
        for(int i=0;i<n;i++)
        {

            int ans=0;
            dfs(i,nums,isVisited,ans);
            result=max(result,ans);
        }
        return result;
    }
};