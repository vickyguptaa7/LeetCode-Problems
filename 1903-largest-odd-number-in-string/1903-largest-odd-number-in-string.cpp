class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.length();
        for(int i=n-1;i>=0;i--)
        {
            int n1=num[i]-'0';
            if((n1&1)==0)
            {
                num.erase(n-1,1);
                n--;
            }
            else
            {
                return num;
            }
        }
        return "";
    }
};