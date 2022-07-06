class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int it1=0,it2=0;
        int n=firstList.size(),m=secondList.size();
        vector<vector<int>> result;
        while(it1<n&&it2<m)
        {
            if(firstList[it1][1]>=secondList[it2][1])
            {
                int leftBndry=max(firstList[it1][0],secondList[it2][0]);
                int rightBndry=secondList[it2][1];
                if(leftBndry<=rightBndry)
                 result.push_back({leftBndry,rightBndry});
                it2++;
            }
            else if(secondList[it2][1]>=firstList[it1][1])
            {
                int leftBndry=max(firstList[it1][0],secondList[it2][0]);
                int rightBndry=firstList[it1][1];
                if(leftBndry<=rightBndry)
                 result.push_back({leftBndry,rightBndry});
                it1++;
            }
        }
        return result;
    }
};