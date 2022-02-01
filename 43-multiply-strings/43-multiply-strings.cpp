class Solution {
public:
    string add_string(string num1,string num2)
    {
        string result;
        int len1=num1.length(),len2=num2.length();
        int i=0,j=0;
        int carry=0;
        while(i<len1||j<len2||carry!=0)
        {
            int ans=carry;
            if(i<len1)
            {
                ans+=num1[i]-'0';
                i++;
            }
            if(j<len2)
            {
                ans+=num2[j]-'0';
                j++;
            }
            carry=ans/10;
            result.push_back((ans%10)+'0');
        }
        return result;
    }
    string oneDigit_multi(string str,int m)
    {
        string result;
        int carry=0;
        int len=str.length();
        int i=0;
        while(i<len)
        {
            int ans=carry+(str[i]-'0')*m;
            carry=ans/10;
            result.push_back((ans%10)+'0');
            i++;
        }
        while(carry!=0)
        {
            int ans=carry;
            carry/=10;
            result.push_back((ans%10)+'0');
        }
        return result;
    }
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0")
        {
            return "0";
        }
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        string result;
        int len1=num1.length(),len2=num2.length();
        for(int i=0;i<len2;i++)
        {
            string temp=oneDigit_multi(num1,num2[i]-'0');
            string temp2;
            for(int j=0;j<i;j++)
            {
                temp2.push_back(0+'0');
            }
            temp2+=temp;
            result=add_string(result,temp2);
        }
        
        reverse(result.begin(),result.end());
        return result;
        
    }
};