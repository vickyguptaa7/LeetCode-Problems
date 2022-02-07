class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int>umap;
        for(auto &x:t)
        {
            umap[x]++;
        }
        for(auto &x:s)
        {
            umap[x]--;
            if(umap[x]==0)
            {
                umap.erase(x);
            }
        }
        char ans;
        for(auto x:umap)
        {
            ans=x.first;
        }
        return ans;
    }
};