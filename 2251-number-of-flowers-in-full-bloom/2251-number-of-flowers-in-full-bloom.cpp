bool mycomp(vector<int>&a,vector<int>&b)
{
    if(a[0]!=b[0])return a[0]<b[0];
    else return a[1]<b[1];
}

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        vector<int>strt,end;
        for(auto x:flowers)
        {
            strt.push_back(x[0]);
            end.push_back(x[1]);
        }
        sort(strt.begin(),strt.end());
        sort(end.begin(),end.end());
        
        vector<int>res;
        for(auto &person:persons)
        {
            int blooms=upper_bound(strt.begin(),strt.end(),person)-strt.begin();
            int noBlooms=lower_bound(end.begin(),end.end(),person)-end.begin();

            // cout<<blooms<<" "<<noBlooms<<"\n";
            res.push_back(blooms-noBlooms);
        }
        return res;
    }
};