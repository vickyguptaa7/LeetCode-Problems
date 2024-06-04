class Solution {
public:
    int longestPalindrome(string s) {
        vector<int>freq(256,0);
        for(auto x:s)freq[x]++;
        int mxOdd=0,ans=0;
        for(auto x:freq)
        {
            ans+=x;
            mxOdd+=x&1?1:0;
        }
        return mxOdd?ans-mxOdd+1:ans;
    }
};