class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int,int>,int>mpairs;
        for(auto rect:rectangles)
        {
            mpairs[{rect[0],rect[1]}]++;
            mpairs[{rect[2],rect[3]}]++;
            mpairs[{rect[2],rect[1]}]--;
            mpairs[{rect[0],rect[3]}]--;
        }
        int edge=0;
        for(auto x:mpairs)
        {
            if(x.second==0)
                continue;
            if(abs(x.second)==1)
                edge++;
            else if(abs(x.second)>1)
                return false;
                
        }
        return edge==4;
    }
};