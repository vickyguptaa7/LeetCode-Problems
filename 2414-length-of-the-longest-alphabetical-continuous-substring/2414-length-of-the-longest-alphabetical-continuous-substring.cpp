class Solution {
public:
    int longestContinuousSubstring(string s) {
        int count=1,longest_substring_length=1;
        for(int i=1;i<s.size();i++)
        {
            if(s[i]-s[i-1]==1)
            {
                count++;
            }
            else 
            {
                count=1;
            }
            longest_substring_length=max(longest_substring_length,count);
        }
        return longest_substring_length;
    }
};