class Solution {
public:
    int firstUniqChar(string s) {
        vector<int>alpha(26,0);
        int indx=-1,n=s.size();
        char ref;
        for(auto x:s)
        {
            alpha[x-'a']++;
        }
        for(int i=0;i<n;i++)
        {
            if(alpha[s[i]-'a']==1)return i; 
        }
        return -1;
    }
};