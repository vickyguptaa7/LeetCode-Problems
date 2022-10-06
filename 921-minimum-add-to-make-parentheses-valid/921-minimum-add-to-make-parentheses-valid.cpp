class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int>par;
        for(auto x:s)
        {
            if(x==')'&&!par.empty()&&par.top()=='(')
            {
                par.pop();
            }
            else
            {
                par.push(x);
            }
        }
        return par.size();
    }
};