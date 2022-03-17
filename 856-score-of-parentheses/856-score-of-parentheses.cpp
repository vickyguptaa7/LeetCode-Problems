class Solution {
public:
    int helper(string s,int &index)
    {
        int score=0,len=s.size();
        while(index<len)
        {
            if(s[index]=='(')
            {
                index++;
                if(s[index]==')')
                {
                    score++;
                }
                else 
                {
                    score+=2*helper(s,index);
                }
            }
            else
            {
                return score;
            }
                                index++;
        }
        return score;
    }
    int scoreOfParentheses(string s) {
        int index=0;
        return helper(s,index);
    }
};