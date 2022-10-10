class Solution {
public:
    string breakPalindrome(string palindrome) {
        if(palindrome.size()==1)
        {
            return "";
        }
        for(int i=0;i<palindrome.size();i++)
        {
            if(palindrome[i]!='a')
            {
                if((palindrome.size()&1)&&i==(palindrome.size())/2)continue;
                palindrome[i]='a';
                return palindrome;
            }
        }
        palindrome.back()='b';
        return palindrome;
    }
};