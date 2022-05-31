class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<int>store;
        string tmp;

        for(int i=0;i<s.size();i++)
        {
            if(tmp.size()<k)
            {
                tmp+=s[i];
            }
            
            if(tmp.size()==k)
            {
                int ans=0;
                for(int i=0;i<tmp.size();i++)
                {
                    if(tmp[i]=='1')
                    {
                        ans+=(1<<i);
                    }
                }
                store.insert(ans);
                tmp=tmp.substr(1);
            }
        }
        int cnt=(1<<k);
        if(store.size()==cnt)return true;
        return false;
    }
};