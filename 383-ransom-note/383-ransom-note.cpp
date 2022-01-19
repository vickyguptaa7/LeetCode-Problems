class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>umap;
        for(auto x:ransomNote)
        {
            umap[x]++;
        }
        for(auto x:magazine)
        {
            if(umap.find(x)!=umap.end())
            {
                umap[x]--;
                if(umap[x]==0)umap.erase(x);
            }
        }
        return umap.empty();
    }
};