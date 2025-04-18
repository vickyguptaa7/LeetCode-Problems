class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
        {
            return "1";
        }
        string str=countAndSay(n-1),nstr="";
        int iter=0,count=0;
        while(iter<str.size())
        {
            count=1;
            while(iter+1<str.size()&&str[iter]==str[iter+1])
            {
                iter++;
                count++;
            }
            nstr+=to_string(count);
            nstr+=str[iter];
            iter++;
        }
        return nstr;
    }
};