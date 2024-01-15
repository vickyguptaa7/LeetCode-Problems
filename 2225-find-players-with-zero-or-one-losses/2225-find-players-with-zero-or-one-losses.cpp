class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int>win,loose;
        for(auto match:matches)
        {
            win[match[0]]++;
            loose[match[1]]++;
        }
        vector<int>noLoose,oneLoose;
        for(auto w:win)
        {
            if(!loose.count(w.first))
                noLoose.push_back(w.first);
        }
        for(auto l:loose)
        {
            if(l.second==1)
                oneLoose.push_back(l.first);
        }
        return {noLoose,oneLoose};
    }
};