class Solution {
public:

    int prod(long long a,long long b)
    {
        int mod=1e9+7;
        return ((a%mod)*(b%mod))%mod;
    }

    int fastExpo(long long a,long long b)
    {
        if(b==1)
            return a;
        if(b==0)
            return 1;
        
        long long ans=fastExpo(a,b/2);
        return b&1?prod(prod(ans,ans),a):prod(ans,ans);
    }

    int countGoodNumbers(long long n) {
        return prod(fastExpo(5,(n+1)/2),fastExpo(4,n/2));
    }
};