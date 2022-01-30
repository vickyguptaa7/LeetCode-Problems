class Solution {
public:
    string addStrings(string num1, string num2) {
        string result;
        int carry=0;
        int len1=num1.length(),len2=num2.length();
        int i=0,j=0;
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        
        while(i<len1&&j<len2)
        {
            int sum=carry+(num1[i]-'0')+(num2[j]-'0');
            carry=sum/10;
            sum%=10;
            result.push_back(sum+'0');
            i++;j++;
        }
        
        while(i<len1)
        {
            int sum=carry+(num1[i]-'0');
            carry=sum/10;
            sum%=10;
            result.push_back(sum+'0');
            i++;
        }
        
        while(j<len2)
        {
            int sum=carry+(num2[j]-'0');
            carry=sum/10;
            sum%=10;
            result.push_back(sum+'0');
            j++;
        }
        
        if(carry!=0)
        {
            result.push_back(carry+'0');
            carry=0;
        }
        reverse(result.begin(),result.end());
        return result;
    }
};