class Solution {
    vector<string>findTheExpression(string &s)
    {
        vector<string>st;
        string curr="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')continue;
            if(s[i]=='+'||s[i]=='*'||s[i]=='/'||s[i]=='-')
            {
                if(!curr.empty())st.push_back(curr);
                curr="";
                curr+=s[i];
                st.push_back(curr);
                curr="";
            }
            else 
            {
                curr+=s[i];
            }
        }
        if(!curr.empty())
            st.push_back(curr);
        return st;
    }
    int precedence(string ch)
    {
        if(ch=="+"||ch=="-")
            return 1;
        return 2;
    }
    int calculateVal(int num1,int num2,string oper)
    {
        if(oper=="*")
            return num1*num2;
        else if(oper=="+")
            return num1+num2;
        else if(oper=="/")
            return num2/num1;
        else 
            return num2-num1;
    }
    bool isOperator(string oper)
    {
        if(oper=="+"||oper=="-"||oper=="*"||oper=="/")
            return true;
        return false;
    }
    public:
    int calculate(string s) {
        vector<string>expr=findTheExpression(s);
        vector<string>result;
        stack<string>oper;
        for(int i=0;i<expr.size();i++)
        {
            if(isOperator(expr[i]))
            {
                while(!oper.empty()&&precedence(expr[i])<=precedence(oper.top()))
                {
                    result.push_back(oper.top());
                    oper.pop();
                }
                oper.push(expr[i]);
            }
            else
            {
                result.push_back(expr[i]);
            }
        }
        while(!oper.empty())
        {
            result.push_back(oper.top());
            oper.pop();
        }

        stack<int>eval;
        for(int i=0;i<result.size();i++)
        {
            cout<<result[i]<<" ";
            if(isOperator(result[i]))
            {
                int num1=eval.top();
                eval.pop();
                int num2=eval.top();
                eval.pop();
                eval.push(calculateVal(num1,num2,result[i]));
            }
            else 
            {
                eval.push(stoi(result[i]));
            }
        }
        return eval.top();
    }
};