class Solution {

    long long gcd(long long a,long long b)
    {
        if(b==0)
            return a;
        return gcd(b,a%b);
    }

public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>mx(n,0);
        for(int i=0;i<n;i++)
        {
            mx[i]=max(nums[i],i==0?0:mx[i-1]);
        }
        vector<int>pre(n,0);
        for(int i=0;i<n;i++)
        {
            pre[i]=gcd(mx[i],nums[i]);
        }
        sort(pre.begin(),pre.end());
        long long ans=0;
        for(int i=0;i<n/2;i++)
        {
            ans+=gcd(pre[i],pre[n-1-i]);
        }
        return ans;
    }
};