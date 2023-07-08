class Solution {
public:
    
    bool checkPallindrome(string &s,int l,int r)
    {
        while(l<r)
        {
            if(s[l]!=s[r])
                break;
            l++;
            r--;
        }
        return l>=r;
    }
    
    bool validPalindrome(string s) {
        bool isPal=true;
        for(int i=0;i<s.size()/2;i++)
        {
            if(s[i]!=s[(int)s.size()-1-i])
            {
                if(checkPallindrome(s,i+1,(int)s.size()-1-i)||
                   checkPallindrome(s,i,(int)s.size()-2-i))
                {
                    isPal=true;
                    break;
                }
                else
                {
                    isPal=false;
                    break;
                }
            }
        }
        return isPal;
    }
};