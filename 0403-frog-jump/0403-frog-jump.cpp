class Solution {
    int dp[2001][2001];
    
    bool helper(int indx,int prev,vector<int>&stones)
    {
        if(indx+1==stones.size())
        {
            cout<<"got\n";
            return true;            
        }
        
        
        if(indx>=stones.size())
            return 0;
        
        if(dp[indx][prev+1]!=-1)
            return dp[indx][prev+1];
        
        int jump=(prev==-1)?0:stones[indx]-stones[prev];
        
        int way=0;
        if(jump>1)
        {
            auto iter=lower_bound(stones.begin(),stones.end(),
                                 stones[indx]+jump-1);
            if(*iter==stones[indx]+jump-1)
                way|=helper(iter-stones.begin(),indx,stones);
        }
        if(way)
            return 1;
        if(jump>0)
        {
        auto iter=lower_bound(stones.begin(),stones.end(),
                                 stones[indx]+jump);
        if(*iter==stones[indx]+jump)
                way|=helper(iter-stones.begin(),indx,stones);
        }
        if(way)
            return 1;
        
        auto iter=lower_bound(stones.begin(),stones.end(),
                                 stones[indx]+jump+1);
        if(*iter==stones[indx]+jump+1)
                way|=helper(iter-stones.begin(),indx,stones);
        
        return dp[indx][prev+1]=way;
    }
    
    
public:
    
    bool canCross(vector<int>& stones) {
        memset(dp,-1,sizeof(dp));
        return helper(0,-1,stones);
    }
};