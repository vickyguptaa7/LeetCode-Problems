class Solution {
public:
    int totalSteps(vector<int>& nums) {
        
        stack<pair<int,int>>st;
        int ans=0,n=nums.size()-1;
        
        st.push({n,0});
        
        for(int i=nums.size()-2;i>=0;i--)
        {
            int cnt=0;
            while(!st.empty()&&nums[st.top().first]<nums[i])
            {
                cnt=max(cnt+1,st.top().second);
                st.pop();
            }
            st.push({i,cnt});
            ans=max(cnt,ans);
        }
        return ans;
    }
};