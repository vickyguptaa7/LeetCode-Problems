class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(),coins.end());
        long long add=0,sum=0;
        for(int i=0;i<coins.size();i++)
        {
            if(sum+1>=coins[i])
            {
                sum+=coins[i];
            }
            else
            {
                add++;
                sum+=sum+1;
                i--;
            }
        }
        while(sum<target)
        {
            add++;
            sum+=sum+1;
        }
        return add;
    }
};