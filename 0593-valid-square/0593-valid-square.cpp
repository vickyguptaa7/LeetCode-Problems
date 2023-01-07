class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<pair<int,int>>cord;
        cord.push_back({p1[0],p1[1]});
        cord.push_back({p2[0],p2[1]});
        cord.push_back({p3[0],p3[1]});
        cord.push_back({p4[0],p4[1]});
        map<long double,int>freq;
        for(auto [x,y]:cord)
        {
            for(auto [_x,_y]:cord)
            {
                if(_x==x&&_y==y)
                    continue;
                freq[(x-_x)*(x-_x)+(y-_y)*(y-_y)]++;
            }
        }
        if(!freq.empty()&&freq.begin()->second==8&&freq.rbegin()->second==4)
            return true;
        return false;
    }
};