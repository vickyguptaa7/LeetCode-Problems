class Solution {
public:
    int maximumLength(string s) {
        int size=-1;
        map<string,int>mp;
        for(int i=0;i<s.size();i++)
        {
            string sub;
            for(int j=i;j<s.size();j++)
            {
                if(j!=i&&s[j]!=s[j-1])
                    break;
                sub+=s[j];
                mp[sub]++;
            }
        }
        for(auto &x:mp)
        {   
            if((int)x.first.size()>size&&x.second>2)
            {
                cout<<x.first<<"\n";
                size=x.first.size();
            }
        }
        return size;
    }
};