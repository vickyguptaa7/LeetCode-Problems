class Solution {
public:
    bool halvesAreAlike(string s) {
        int cnt=0,n=s.size();
        vector<char>vowel={'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for(int i=0;i<n/2;i++)
        {
            if(find(vowel.begin(),vowel.end(),s[i])!=vowel.end())
            {
                cnt++;
            }
        }
        for(int i=n/2;i<n;i++)
        {
            if(find(vowel.begin(),vowel.end(),s[i])!=vowel.end())
            {
                cnt--;
            }
        }
        return cnt==0;
    }
};