class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
        {
            return "1";
        }else if(n==2)
        {
            return "11";
        }
        
        string  str="11";
        n=n-2;
        while(n--)
        {
            string temp;
            int len=str.length();
            int counter=1;
            for(int i=1;i<len;i++)
            {
                if(str[i-1]==str[i])
                {
                    counter++;
                }
                else
                {
                    temp+=to_string(counter)+str[i-1];
                    counter=1;
                }
            }
            temp+=to_string(counter)+str[len-1];
            str=temp;
        }
        return str;
    }
};