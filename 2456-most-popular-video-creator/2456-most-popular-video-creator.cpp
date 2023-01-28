class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        map<string,long long>cview;
        map<string,int>mvid;
        for(int i=0;i<creators.size();i++)
        {
            cview[creators[i]]+=views[i];
            if(mvid.count(creators[i]))
            {
                if(views[mvid[creators[i]]]==views[i]&&ids[mvid[creators[i]]]>ids[i])
                {
                    mvid[creators[i]]=i;
                }
                else if(views[mvid[creators[i]]]<views[i])
                {
                    mvid[creators[i]]=i;
                }
            }
            else 
            {
                mvid[creators[i]]=i;
            }
        }
        long long Max=0;
        vector<vector<string>>res;
        for(auto x:cview)
        {
            Max=max(x.second,Max);
        }
        for(auto x:cview)
        {
            if(x.second==Max)
            {
                res.push_back({x.first,ids[mvid[x.first]]});
            }
        }
        return res;
    }
};