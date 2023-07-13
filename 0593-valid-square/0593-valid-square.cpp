class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<pair<int,int>>coord;
        coord.push_back({p1[0],p1[1]});
        coord.push_back({p2[0],p2[1]});
        coord.push_back({p3[0],p3[1]});
        coord.push_back({p4[0],p4[1]});
        map<int,int>freq;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(i==j||coord[i]==coord[j])continue;
                int x=coord[i].first-coord[j].first;
                int y=coord[i].second-coord[j].second;
                freq[x*x+y*y]++;
            }
        }
        if(freq.size()==2&&freq.begin()->second==8&&freq.rbegin()->second==4)
            return true;
        return false;
    }
};