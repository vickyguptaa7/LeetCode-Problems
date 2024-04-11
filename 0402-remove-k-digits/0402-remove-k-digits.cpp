class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size()==k)return "0";
        string res;
        for(int i=0;i<num.size();i++)
        {
            if(k&&!res.empty()&&res.back()>num[i])
            {
                res.pop_back();
                i--;
                k--;
            }
            else
            {
                res+=num[i];
            }
        }
        int rem=0;
        for(int i=0;i<res.size();i++)
        {
            if(res[i]!='0')break;
            rem++;
        }
        res=res.substr(rem);
        res=res.substr(0,max(0,(int)res.size()-k));
        return res.empty()?"0":res;
    }
};