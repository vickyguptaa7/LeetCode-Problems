class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int prev=values[0],res=0;
        for(int i=1;i<values.size();i++)
        {
            prev--;
            res=max(res,prev+values[i]);
            if(prev<values[i])
            {
                prev=values[i];
            }
        }
        return res;
    }
};