class Solution {
public:
    vector<int>stringToNumber(string version)
    {
        vector<int>v1;
        string s;
        for(int i=0;i<version.size();i++)
        {
            if(version[i]!='.')
            s+=version[i];
            
            if(version[i]=='.')
            {
                v1.push_back(stoi(s));
                s="";
            }
        }
        if(s.size()>0)
        {
                v1.push_back(stoi(s));
                s="";
        }
        int iter=v1.size()-1;
        while(iter>0&&v1[iter]==0)
        {
            v1.erase(v1.begin()+iter);
            iter--;
        }
        return v1;
    }
    int compareVersion(string version1, string version2) {
        vector<int>v1=stringToNumber(version1);
        vector<int>v2=stringToNumber(version2);
        int min_len=min(v1.size(),v2.size());
        for(int i=0;i<min_len;i++)
        {
            if(v1[i]>v2[i])
            {
                return 1;
            }
            if(v1[i]<v2[i])
            {
                return -1;
            }
        }
        if(v1.size()==v2.size())return 0;
        else if(v1.size()>v2.size())return 1;
        else return -1;
    }
};