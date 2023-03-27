class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int cost=0;
        for(int i=startPos[0];i<homePos[0];i++)
        {
            cost+=rowCosts[i+1];
        }
        for(int i=startPos[0];i>homePos[0];i--)
        {
            cost+=rowCosts[i-1];
        }
        
        for(int i=startPos[1];i<homePos[1];i++)
        {
            cost+=colCosts[i+1];
        }
        for(int i=startPos[1];i>homePos[1];i--)
        {
            cost+=colCosts[i-1];
        }
        return cost;
    }
};