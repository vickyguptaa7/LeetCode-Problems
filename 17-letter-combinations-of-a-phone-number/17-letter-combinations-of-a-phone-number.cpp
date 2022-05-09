class Solution {
public:
    vector<string>keys={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> letterCombinations(string digits) {
        vector<string>result;
        if(digits.empty())return result;
        helper(0,"",digits,result);
        return result;
    }
    void helper(int s,string ans,string &digits,vector<string>&result)
    {
        if(digits.size()==s)
        {
            result.push_back(ans);
            return;
        }
        int digit=digits[s]-'0';
        for(int i=0;i<keys[digit].size();i++)
        {
            helper(s+1,ans+keys[digit][i],digits,result);
        }
    }
};