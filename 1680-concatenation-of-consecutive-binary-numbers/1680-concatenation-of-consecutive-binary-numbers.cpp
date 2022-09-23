vector<long long>dp(3e6+1,-1);
class Solution {
public:
    long long binpow(long long a, long long b, long long m) {
    a %= m;
    int indx=b;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    dp[indx]=res;
    return res;
}
    int concatenatedBinary(int n) {
        long long result=0,mod=1e9+7;
        long long iter=0;
        for(int i=n;i>=1;i--)
        {
            int num=i;
            while(num)
            {
                if(num&1)
                {
                    if(dp[iter]!=-1)
                        result+=dp[iter];
                    else 
                        result+=binpow(2,iter,mod);
                    result%=mod;
                }
                iter++;
                num/=2;
            }
        }
        cout<<iter<<"\n";
        return result;
    }
};