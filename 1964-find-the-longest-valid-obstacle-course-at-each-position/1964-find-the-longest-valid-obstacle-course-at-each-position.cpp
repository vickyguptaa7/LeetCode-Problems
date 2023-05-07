class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int>result,ans;
        for(int i=0;i<obstacles.size();i++)
        {
            int indx=upper_bound(result.begin(),result.end(),obstacles[i])-result.begin();
            if(indx==result.size())
            {
                result.push_back(obstacles[i]);
                ans.push_back(result.size());
            }
            else 
            {
                result[indx]=obstacles[i];
                ans.push_back(indx+1);
            }
        }
        return ans;
    }
};