class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>umap1,umap2;
        int len1=s1.length(),len2=s2.length();
        if(len1>len2)return false;
        for(int i=0;i<len1;i++)
        {
            umap1[s1[i]]++;
            umap2[s2[i]]++;
        }
        int i=0,j=len1;
        while(j<len2)
        {
            while(j-i+1<=len1)
            {
                umap2[s2[j++]]++;
            }
            if(umap1==umap2)return true;
            umap2[s2[i]]--;
            if(umap2[s2[i]]==0)
            {
                umap2.erase(s2[i]);
            }
            i++;
        }
        if(umap1==umap2)return true;
        else
        return false;
    }
};