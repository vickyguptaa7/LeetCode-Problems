class Solution {
public:

    long long prod(long long a,long long b,int mod)
    {
        return ((a%mod)*(b%mod))%mod;
    }

    long long binpow(long long a,long long b,int mod)
    {
        if(b==0)
        {
            return 1;
        }
        long long temp=binpow(a,b/2,mod);
        if(b&1)
        {
            return prod(prod(temp,temp,mod),a,mod);
        }
        return prod(temp,temp,mod);
    }

    long long add(long long a,long long b,int mod)
    {
        return (a%mod+b%mod)%mod;
    }

    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            int indx=upper_bound(nums.begin(),nums.end(),target-nums[i])-nums.begin();
            if(indx<=i)break;
            cnt=add(cnt,binpow(2,indx-i-1,1e9+7),1e9+7);
        }
        return cnt;
    }
};