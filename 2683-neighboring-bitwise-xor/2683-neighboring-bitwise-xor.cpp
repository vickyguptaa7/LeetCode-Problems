class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int val=0;
        for(auto x:derived)val^=x;
        return val==0;
    }
};