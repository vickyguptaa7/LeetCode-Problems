class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        map<int,vector<int>>coordx,coordy;
        for(auto building:buildings)
        {
            coordx[building[0]].push_back(building[1]);
            coordy[building[1]].push_back(building[0]);
        }
        for(auto &x:coordx)
        {
            sort(x.second.begin(),x.second.end());
        }
        for(auto &x:coordy)
        {
            sort(x.second.begin(),x.second.end());
        }
        int count=0;
        for(auto building:buildings)
        {
            int x=building[0],y=building[1];
            if(!coordx.count(x)||!coordy.count(y))continue;
            
            int i1=upper_bound(coordx[x].begin(),coordx[x].end(),y)-coordx[x].begin();
            int i2=upper_bound(coordy[y].begin(),coordy[y].end(),x)-coordy[y].begin();
            i1--;
            i2--;
            if(i1>0&&i2>0&&i1+1<coordx[x].size()&&i2+1<coordy[y].size())
            {
                count++;
            }
        }
        return count;
    }
};