class Solution {
public:
    
    bool isPal(string &str,int left,int right)
    {
        while(left<right&&str[left]==str[right])
        {
            left++;
            right--;
        }
        return left>=right;
    }
    void helper(int strt,vector<string>curr,string &str,vector<vector<string>>&result)
    {
        if(strt==str.size())
        {
            result.push_back(curr);
            return;
        }
        for(int i=strt;i<str.size();i++)
        {
            if(isPal(str,strt,i))
            {
                curr.push_back(str.substr(strt,i-strt+1));
                helper(i+1,curr,str,result);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>result;
        vector<string>curr;
        helper(0,curr,s,result);
        return result;
    }
};