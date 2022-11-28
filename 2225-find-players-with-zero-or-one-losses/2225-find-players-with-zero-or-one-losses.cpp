class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n=matches.size();
        map<int,int>stat;
        vector<vector<int>>res;
        vector<int>win,lose;
        for(int i=0;i<n;i++)
        {
            stat[matches[i][0]];
            stat[matches[i][1]]++;
        }
        for(auto x:stat)
        {
            if(x.second==0)
                win.push_back(x.first);
            else if(x.second==1) 
                lose.push_back(x.first);
        }
        sort(win.begin(),win.end());
        sort(lose.begin(),lose.end());
        res.push_back(win);
        res.push_back(lose);
        return res;
    }
};