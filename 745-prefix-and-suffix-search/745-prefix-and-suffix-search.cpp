class WordFilter {
    map<string,int>omap;
public:
    WordFilter(vector<string>& words) {
        
        int n=words.size();
        set<string>oset;
        for(int i=n-1;i>=0;i--)
        {
            if(oset.count(words[i]))
            {
                continue;
            }
            oset.insert(words[i]);
            string suff;
            int m=words[i].size();
            
            for(int j=0;j<m;j++)
            {
                suff=words[i][m-1-j]+suff;
                string pref;
                for(int k=0;k<m;k++)
                {
                    pref+=words[i][k];
                    string preSuff=pref+"-"+suff;
                    if(!omap.count(preSuff))
                    omap[preSuff]=i;
                }
            }
        }
    }
    
    int f(string pref, string suff) {
        string preSuff=pref+"-"+suff;
        if(omap.count(preSuff))
        {
            return omap[preSuff];
        }
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */