class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int odd=0;
        for(auto &x:arr)
        {
            odd=x&1?odd+1:0;
            if(odd==3)return true;
        }
        return false;
    }
};