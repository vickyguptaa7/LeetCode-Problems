class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int n=s.size();
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=s[n-1-i])
            {
                s[i]=min(s[n-1-i],s[i]);
                s[n-1-i]=min(s[n-1-i],s[i]);
            }
        }
        return s;
    }
};