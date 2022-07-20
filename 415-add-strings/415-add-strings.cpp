class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1=num1.size(),n2=num2.size();
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        
        int carry=0;
        int size=max(n1,n2);
        string res;
        for(int i=0;i<size;i++)
        {
            int sum=carry;
            if(i<n1)
            {
                sum+=num1[i]-'0';
            }
            if(i<n2)
            {
                sum+=num2[i]-'0';
            }
            carry=sum/10;
            sum%=10;
            res+=to_string(sum);
        }
        if(carry!=0)
            res+=to_string(carry);
        
        reverse(res.begin(),res.end());
        return res;
    }
};