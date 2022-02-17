bool mycomp(vector<int>v1,vector<int>v2)
{
    return (v1[1]>v2[1]);
}
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),mycomp);
        int cost=0;
        int n=boxTypes.size();
        for(int i=0;i<n;i++)
        {
            if(truckSize>=boxTypes[i][0])
            {
                cost+=boxTypes[i][0]*boxTypes[i][1];
                truckSize-=boxTypes[i][0];
            }
            else if(truckSize>0)
            {
                cost+=truckSize*boxTypes[i][1];
                truckSize=0;
            }
            else
            {
                break;
            }
        }
        return cost;
    }
};