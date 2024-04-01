class Solution {
public:
    int lengthOfLastWord(string s) {
        int len=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')continue;
            
            len=0;
            while(i<s.size()&&s[i]!=' ')
            {
                len++;
                i++;
            }
            i--;
        }
        return len;
    }
};