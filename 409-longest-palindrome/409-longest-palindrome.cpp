class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>umap;
        for(auto &x:s)
        {
            umap[x]++;
        }
        int pallindrome_length=0;
        bool isOdd=false;
        for(auto &x:umap)
        {
            if((x.second&1)==0)
            {
                pallindrome_length+=x.second;
            }
            else{
                pallindrome_length+=x.second-1;
                isOdd=true;
            }
        }
        return pallindrome_length+isOdd;
    }
};