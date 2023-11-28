class Solution {
public:
    
    int numberOfWays(string corridor) {
        int size=corridor.size();
        int mod=1e9+7;
        int res=1,seat_count=0,prev=-1;
        vector<int>cord;
        for(int i=0;i<size;i++)
        {
            if(corridor[i]=='S')cord.push_back(i);
        }
        if(cord.size()%2==1||cord.empty())
            return 0;
        for(int i=2;i<cord.size();i+=2)
        {
            res=(res*1ll*(cord[i]-cord[i-1]))%mod;
        }
        return res;
    }
};