typedef long long ll;
class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        int total=(1<<13)-1;
        int profitNum=0,profitVal=0;
        for(int i=1;i<=total;i++)
        {
            int num=i,iter=0;
            int cost=0,profit=0;
            while(iter<12)
            {
                if(num&1)
                {
                    cost+=aliceArrows[iter]+1;
                    profit+=iter;
                }
                num/=2;
                iter++;
            }
            if(cost<=numArrows&&profitVal<profit)
            {
                profitVal=profit;
                profitNum=i;
            }
        }
        vector<int>bob(12,0);
        for(int i=0;i<12;i++)
        {
            if(profitNum&1)
            {
                bob[i]=aliceArrows[i]+1;
                numArrows-=aliceArrows[i]+1;
            }
            profitNum/=2;
        }
        bob[0]=max(numArrows,0);
        return bob;
    }
};