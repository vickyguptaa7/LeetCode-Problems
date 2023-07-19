class Solution {
public:
    string removeDuplicates(string s) {
        string ns;
        for(auto x:s)
        {
            if(!ns.empty()&&ns.back()==x)
            {
                ns.pop_back();
            }
            else
            {
                ns.push_back(x);
            }
        }
        return ns;
    }
};