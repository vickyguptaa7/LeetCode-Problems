class Solution {
public:
    int countOrders(int n) {
        long long res=1,mod=1e9+7;
        for(int i=2;i<=2*n;i++)
        {
            res*=i;
            if((i&1)==0)
                res/=2;
            res%=mod;
        }
        return int(res);
    }
};