class Solution {
public:
    int possibleStringCount(string word) {
        int ans=1,cnt=1;
        for(int i=1;i<word.size();i++)
        {
            if(word[i]==word[i-1])
            {
                cnt++;
            }
            else
            {
                ans+=cnt-1;
                cnt=1;
            }
        }
        ans+=cnt-1;
        return ans;
    }
};