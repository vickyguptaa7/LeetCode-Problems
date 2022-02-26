class Solution {
public:
    string breakPalindrome(string palindrome) {
        int len=palindrome.size();
        if(len==1)return "";
        
        for(int i=0;i<len;i++)
        {
            if(len&1==1&&i==len/2)continue;
            
            if(palindrome[i]=='a')continue;
            else 
            {
                palindrome[i]='a';
                return palindrome;
            }
        }
        
        palindrome[len-1]='b';
        return palindrome;
    }
};