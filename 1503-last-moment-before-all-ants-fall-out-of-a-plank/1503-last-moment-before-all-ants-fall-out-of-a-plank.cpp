class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxTime=0;
        for(auto x:left)
        {
            maxTime=max(maxTime,x);
        }
        for(auto x:right)
        {
            maxTime=max(maxTime,n-x);
        }
        return maxTime;
    }
};