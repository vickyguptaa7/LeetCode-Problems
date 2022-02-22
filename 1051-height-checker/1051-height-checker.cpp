class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>newh(heights.begin(),heights.end());
        sort(newh.begin(),newh.end());
        int counter=0;
        for(int i=0;i<newh.size();i++)
        {
            if(heights[i]!=newh[i])
            {
                counter++;
            }
        }
        return counter;
    }
};