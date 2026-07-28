class Solution {
public:
    string smallestPalindrome(string s) {
        
        int freq[26];
        for(int i=0;i<26;i++)
            freq[i]=0;
        for(int i=0;i<s.size();i++)
        {
            freq[s[i]-'a']++;
        }
        string res,odd;
        for(int i=0;i<26;i++)
        {
            for(int j=0;j<freq[i]/2;j++)
                res+=(i+'a');
            if(freq[i]%2)odd+=(i+'a');
        }
        string temp = res;
        reverse(temp.begin(),temp.end());

        return res+odd+temp;
    }
};