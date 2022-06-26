class Solution {
public:
    int countHousePlacements(int n) {
        long long prev=1,curr=1,mod=1e9+7;
        for(int i=0;i<n;i++)
        {
            long long newCurr=curr+prev;
            prev=curr%mod;
            curr=newCurr%mod;
        }
        long long res=curr%mod;
        res*=res;
        res%=mod;
        return res;
    }
};