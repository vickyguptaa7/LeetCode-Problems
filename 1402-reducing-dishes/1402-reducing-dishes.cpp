class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int satisfSum=
            accumulate(satisfaction.begin(),satisfaction.end(),0ll);
        int currSum=0,len=satisfaction.size();
        for(int i=0;i<len;i++)
        {
            currSum+=(i+1)*satisfaction[i];
        }
        int maxSum=currSum;
        for(int i=0;i<len;i++)
        {
            currSum-=satisfSum;
            satisfSum-=satisfaction[i];
            maxSum=max(maxSum,currSum);
        }
        return maxSum;
    }
};