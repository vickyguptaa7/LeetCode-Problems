class Solution {
public:
    
    string backSpace(string s)
    {
        string ans;
        for(auto x:s)
        {
            if(x=='#')
            {
                if(!ans.empty())
                    ans.pop_back();
            }
            else
            {
                ans.push_back(x);
            }
        }
        return ans;
    }
    
    bool backspaceCompare(string s, string t) {
        return backSpace(s)==backSpace(t);
    }
};