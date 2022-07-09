typedef pair<int,int> pi;
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        vector<int>dp(nums.size(),-1e9);
        
        priority_queue<pi>pque;
        
        dp[0]=nums[0];
        pque.push({nums[0],0});
        
        for(int i=1;i<nums.size();i++)
        {
            while(!pque.empty()&&pque.top().second<i-k)
            {
                pque.pop();
            }
            dp[i]=nums[i];
            if(!pque.empty())dp[i]+=pque.top().first;
            pque.push({dp[i],i});
        }
        return dp[nums.size()-1];
    }
};