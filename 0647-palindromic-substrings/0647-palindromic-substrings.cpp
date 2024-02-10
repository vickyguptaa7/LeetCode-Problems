class Solution {
public:
    
    int helper(int s,int e,string &str)
    {
        int cntr=0;
        while(s>=0&&e<str.size()&&str[s]==str[e])
        {
            s--;
            e++;
            cntr++;
        }
        return cntr;
    }
    
    int countSubstrings(string s) {
        int res=1;
        for(int i=1;i<s.size();i++)
        {
            res+=helper(i,i,s);
            res+=helper(i-1,i,s);
        }
        return res;
    }
};