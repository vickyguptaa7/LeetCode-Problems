class Solution {
public:
    string customSortString(string order, string s) {
        vector<int>freq(26,0);
        for(auto &x:s)freq[x-'a']++;
        string res;
        for(auto &x:order)
        {
            for(int i=0;i<freq[x-'a'];i++)res+=x;
            freq[x-'a']=0;
        }
        for(int i=0;i<26;i++)
        {
            for(int j=0;j<freq[i];j++)res+=char(i+'a');
        }
        return res;
    }
};