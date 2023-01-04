class Solution {
public:
    int numberOfSubstrings(string s) {
        int occurence=0,size=s.size(),curr=0,prev=0;
        vector<int>freq(3,0);
        while(curr<size)
        {
            if(freq[0]&&freq[1]&&freq[2])
            {
                occurence+=size-curr+1;
                freq[s[prev++]-'a']--;
            }
            else
            {
                freq[s[curr++]-'a']++;
            }
        }
        while(freq[0]&&freq[1]&&freq[2]&&prev<size)
        {
            occurence+=1;
            freq[s[prev++]-'a']--;
        }
        return occurence;
    }
};