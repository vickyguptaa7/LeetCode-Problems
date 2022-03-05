class Solution {
public:
    
    int helper(string s,int &i)
    {
        int score=0,n=s.size();
        while(i<n)
        {
            if(s[i]=='(')
            {
                i++;
                if(s[i]==')')
                {
                    score++;
                    i++;
                }
                else
                {
                    score+=2*helper(s,i);
                }
            }
            else
            {
                i++;
                break;
            }
        }
        return score;
    }
    int scoreOfParentheses(string s) {
        int i=0;
        return helper(s,i);
    }
};