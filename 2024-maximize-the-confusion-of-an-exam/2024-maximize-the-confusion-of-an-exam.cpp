class Solution {
public:
    
    int helper(string &answerKey,int k,char ch)
    {
        int mx=0,prev=0;
        for(int i=0;i<answerKey.size();i++)
        {
            if(ch==answerKey[i])
                k--;
            while(k<0)
            {
                if(ch==answerKey[prev++])
                    k++;
            }
            mx=max(mx,i-prev+1);
        }
        return mx;
    }
    
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(helper(answerKey,k,'T'),helper(answerKey,k,'F'));
    }
};