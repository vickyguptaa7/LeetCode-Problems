class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int sum=0,mn=1e9,mx=-1e9;
        for(auto diff:differences)
        {
            sum+=diff;
            mn=min(mn,sum);
            mx=max(mx,sum);
        }
        int ans=0;
        for(int i=lower;i<=upper;i++)
        {
            ans+=(i+mn>=lower&&i+mx<=upper);
        }
        return ans;
    }
};