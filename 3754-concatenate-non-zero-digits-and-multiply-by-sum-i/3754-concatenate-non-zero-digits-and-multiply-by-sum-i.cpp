class Solution {
public:
    long long sumAndMultiply(int n) {
        string str=to_string(n);
        long long ans=0;
        int sum=0;
        for(int i=0;i<str.size();i++)
        {
            sum+=str[i]-'0';
            if(str[i]=='0')
                continue;
            ans=ans*10+(str[i]-'0');
        }
        return ans*sum;
    }
};