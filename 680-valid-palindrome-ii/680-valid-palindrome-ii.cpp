class Solution {
public:
    bool isPallindrome(string s,int l,int h)
    {
        while(l<h)
        {
            if(s[l]!=s[h])
            {
                return false;
            }
            l++;h--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int len=s.size();
        bool isRemove=false;
        int low=0,high=len-1;
        while(low<high)
        {
            if(s[low]!=s[high])
            {
                if(isRemove)
                {
                    return false;
                }
                isRemove=true;
                if(isPallindrome(s,low+1,high)||isPallindrome(s,low,high-1))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                low++;
                high--;
            }
        }
        return true;
    }
};