class Solution {
public:
    string reverseWords(string s) {
        string rev;
        string word;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
            {
                reverse(word.begin(),word.end());
                if(rev.empty())rev+=word;
                else
                {
                    rev+=" ";
                    rev+=word;
                }
                word="";
            }
            else
            {
                word+=s[i];
            }
        }
        if(!word.empty())
        {
            reverse(word.begin(),word.end());
            if(rev.empty())rev+=word;
            else
            {
                rev+=" ";
                rev+=word;
            }
        }
        return rev;
    }
};