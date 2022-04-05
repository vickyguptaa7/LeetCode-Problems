class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int n=piles.size()/3;
        int res=0,iter=piles.size()-2;
        while(n--)
        {
            res+=piles[iter];
            iter-=2;
        }
        return res;
    }
};