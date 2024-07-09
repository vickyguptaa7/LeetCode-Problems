class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ans=0,chefTime=0;
        for(int i=0;i<customers.size();i++)
        {
            if(customers[i][0]>=chefTime)
            {
                ans+=customers[i][1];
                chefTime=customers[i][0]+customers[i][1];
            }
            else
            {
                ans+=customers[i][1]+(chefTime-customers[i][0]);
                chefTime+=customers[i][1];
            }
        }
        ans/=customers.size();
        return ans;
    }
};