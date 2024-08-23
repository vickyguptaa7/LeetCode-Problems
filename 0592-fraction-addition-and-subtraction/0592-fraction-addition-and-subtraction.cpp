class Solution {
public:
    string fractionAddition(string expression) {
        vector<pair<int,int>>arr;
        int it=0,deno=1;
        while(it<expression.size())
        {
            bool isNeg=expression[it]=='-'?true:false;
            if(expression[it]=='-'||expression[it]=='+')
            {
                it++;
            }
            int num1=0,num2=0;
            while(it<expression.size()&&isdigit(expression[it]))
            {
                num1=((expression[it]-'0')%10)+num1*10;
                it++;
            }
            if(isNeg)num1=-num1;
            it++;
            isNeg=expression[it]=='-'?true:false;
            if(expression[it]=='-'||expression[it]=='+')
            {
                it++;
            }
            while(it<expression.size()&&isdigit(expression[it]))
            {
                num2=((expression[it]-'0')%10)+num2*10;
                it++;
            }
            if(isNeg)num2=-num2;
            arr.push_back({num1,num2});
            if(deno%num2!=0)
                deno*=num2;
        }
        int num=0;
        for(auto &x:arr)num+=((x.first*1ll*deno)/x.second);
        if(num==0)
        {
            return "0/1";
        }
        bool isNeg=num<0?true:false;
        return to_string(num/__gcd(abs(num),deno))+"/"+to_string(deno/__gcd(abs(num),deno));
    }
};