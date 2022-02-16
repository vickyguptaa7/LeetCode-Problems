class Solution {
public:
    vector<int> diStringMatch(string s) {
       int low=0,high=s.length();
        vector<int>res;
        for(auto &x:s)
        {
            if(x=='I')res.push_back(low++);
            else res.push_back(high--);
        }
        res.push_back(low);
        return res;
    }
};