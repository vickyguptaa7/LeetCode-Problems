class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int oc=0;
        for(int i=0;i<s.size();i++)
        {
            oc+=s[i]=='1';
        }
        string res;
        for(int i=0;i<s.size();i++)res+=(i<oc-1)?"1":"0";
        res.back()='1';
        return res;
    }
};