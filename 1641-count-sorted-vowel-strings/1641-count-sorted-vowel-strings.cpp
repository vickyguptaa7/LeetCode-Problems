class Solution {
public:
    vector<char>vowel={'a','e','i','o','u'};
    int countVowelStrings(int n) {
        int res=0;
        string str;
        return helper(n,0);
    }
    int helper(int n,int prev)
    {
        if(n<=0)
        {
           return 1;
        }
        int sum=0;
        for(int i=prev;i<5;i++)
        {
            sum+=helper(n-1,i);    
        }
        return sum;
    }
};