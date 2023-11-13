class Solution {
public:
    string sortVowels(string s) {
        vector<bool>isVowel(26,0);
        isVowel['a'-'a']=1;
        isVowel['e'-'a']=1;
        isVowel['i'-'a']=1;
        isVowel['o'-'a']=1;
        isVowel['u'-'a']=1;
        vector<int>lower(26,0),upper(26,0);
        for(auto ch:s)
        {
            if(ch>='A'&&ch<='Z')
            {
                if(isVowel[ch-'A'])
                    upper[ch-'A']++;
            }
            else
            {
                if(isVowel[ch-'a'])
                    lower[ch-'a']++;
            }
        }
        queue<pair<char,int>>que;
        for(int i=0;i<26;i++)
        {
            if(upper[i])
              que.push({i+'A',upper[i]});
        }
        for(int i=0;i<26;i++)
        {
            if(lower[i])
              que.push({i+'a',lower[i]});
        }
        string res;
        for(auto ch:s)
        {
            if((ch>='A'&&ch<='Z'&&isVowel[ch-'A'])||(ch>='a'&&ch<='z'&&isVowel[ch-'a']))
            {
                char nch=que.front().first;
                int freq=que.front().second;
                que.front().second--;
                if(freq==1)
                {
                    que.pop();
                }
                res+=nch;
            }
            else
            {
                res+=ch;
            }
        }
        return res;
    }
};