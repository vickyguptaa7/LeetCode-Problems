class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int winSize=cardPoints.size();
        winSize-=k;
        int sum=accumulate(cardPoints.begin(),cardPoints.end(),0);
        int winSum=0;
        for(int i=0;i<winSize;i++)
        {
            winSum+=cardPoints[i];
        }
        int temp=winSum;
        for(int i=winSize;i<cardPoints.size();i++)
        {
            winSum+=cardPoints[i];
            winSum-=cardPoints[i-winSize];
            temp=min(winSum,temp);
        }
        return sum-temp;
    }
};