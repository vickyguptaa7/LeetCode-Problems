class Solution {
    
    string helper(int &indx,string&s)
    {
        string res;
        while(indx<s.size()&&s[indx]!=']')
        {
            if(!isdigit(s[indx]))
                res+=s[indx++];
            else 
            {
                int num=0;
                while(indx<s.size()&&isdigit(s[indx]))
                    num=num*10+(s[indx++]-'0');
                indx++;
                string newres=helper(indx,s);
                indx++;
                while(num-->0)
                    res+=newres;
            }
        }
        return res;
    }
    
public:

    string decodeString(string s) {
        int indx=0;
        return helper(indx,s);
    }
};