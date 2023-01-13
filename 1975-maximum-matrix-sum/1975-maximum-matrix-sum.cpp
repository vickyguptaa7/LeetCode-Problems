class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int negCnt=0,mnEle=1e9;
        long long sum=0;
        for(auto x:matrix)
        {
            for(auto y:x)
            {
                if(y<0)
                    negCnt++;
                sum+=abs(y);
                mnEle=min(abs(y),mnEle);
            }
        }
        if(negCnt&1)
        {
            sum-=2*mnEle;
        }
        return sum;
    }
};