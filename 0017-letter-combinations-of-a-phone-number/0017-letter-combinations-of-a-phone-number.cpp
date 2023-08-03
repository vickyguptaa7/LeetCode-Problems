class Solution {
    
    void helper(int indx,string &digits,vector<string>&keypad,string &curr,
                vector<string>&result)
    {
        if(indx==digits.size())
        {
            result.push_back(curr);
            return;
        }
        int currNum=digits[indx]-'2';
        for(int i=0;i<keypad[currNum].size();i++)
        {
            curr.push_back(keypad[currNum][i]);
            helper(indx+1,digits,keypad,curr,result);
            curr.pop_back();
        }
    }
    
public:
    
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return {};
        vector<string>keypad={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>result;
        string curr;
        helper(0,digits,keypad,curr,result);
        return result;
    }
};