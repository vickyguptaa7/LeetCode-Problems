class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int>timeMinute;
        bool isZero=false;
        for(auto x:timePoints)
        {
            int minute=stoi(x.substr(0,2))*60+stoi(x.substr(3,2));
            timeMinute.push_back(minute);
            timeMinute.push_back(24*60+minute);
        }
        sort(timeMinute.begin(),timeMinute.end());
        int ans=1e9;
        for(int i=1;i<timeMinute.size();i++)
        {
            ans=min(ans,timeMinute[i]-timeMinute[i-1]);
        }
        return ans;
    }
};