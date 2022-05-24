class Solution {
public:
    int helper(string s)
    {
        int left=0,right=0,size=s.size();
        int result=0;
        for(int i=0;i<size;i++)
        {
            if(s[i]=='(')left++;
            else right++;
            
            if(left==right)
            {
                result=max(result,left+right);
            }
            if(right>left)
            {
                left=0;
                right=0;
            }
        }
        left=0;right=0;
        for(int i=size-1;i>=0;i--)
        {
            if(s[i]=='(')left++;
            else right++;
            
            if(left==right)
            {
                result=max(result,left+right);
            }
            if(right<left)
            {
                left=0;
                right=0;
            }
        }
        return result;
    }
    int longestValidParentheses(string s) {
        return helper(s);
    }
};