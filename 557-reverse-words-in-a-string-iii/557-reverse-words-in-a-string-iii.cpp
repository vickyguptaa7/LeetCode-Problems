class Solution {
public:
    string reverseWords(string s) {
        string reverseWord;
        stack<char>stck;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
            {
                while(!stck.empty())
                {
                    reverseWord+=stck.top();
                    stck.pop();
                }
                reverseWord+=' ';
            }
            else
            {
                stck.push(s[i]);
            }
        }
        while(!stck.empty())
        {
            reverseWord+=stck.top();
            stck.pop();
        }
        return reverseWord;
    }
};