class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<vector<int>>mati;
        vector<vector<int>>matv;
        vector<pair<int,int>>temp;
        for(int i=0;i<nums.size();i++)temp.push_back({nums[i],i});
        sort(temp.begin(),temp.end());
        int cntr=1;
        mati.push_back({temp[0].second});
        matv.push_back({temp[0].first});
        for(int i=1;i<temp.size();i++)
        {
            if(temp[i].first-temp[i-1].first>limit)
            {
                cntr++;
            }
            if(mati.size()<cntr)
            {
                mati.push_back({});
                matv.push_back({});
            }
            // cout<<cntr<<" "<<mati.size()<<" "<<matv.size()<<"\n";
            mati[cntr-1].push_back(temp[i].second);
            matv[cntr-1].push_back(temp[i].first);
        }
        for(int i=0;i<mati.size();i++)
        {
            sort(mati[i].begin(),mati[i].end());
            sort(matv[i].begin(),matv[i].end());
        }
        
        for(int i=0;i<mati.size();i++)
        {
            for(int j=0;j<mati[i].size();j++)
            {
                nums[mati[i][j]]=matv[i][j];
            }
        }
        return nums;
    }
};