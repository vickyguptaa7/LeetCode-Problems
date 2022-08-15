class Solution {
public:
    
    int convert(char ch)
    {
        switch(ch)
        {
            case 'I':return 1;
            case 'V':return 5;
            case 'X':return 10;
            case 'L':return 50;
            case 'C':return 100;
            case 'D':return 500;
            case 'M':return 1000;
        }
        return 0;
    }
    int romanToInt(string s) {
        int ans=0;
        for(auto x:s)
        {
            ans+=convert(x);
        }
        for(int i=1;i<s.size();i++)
        {
            if(convert(s[i-1])<convert(s[i]))ans-=2*convert(s[i-1]);
        }
        return ans;
    }
};