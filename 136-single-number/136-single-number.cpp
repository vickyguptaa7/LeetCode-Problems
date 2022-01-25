class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int Num_Xor=0;
        for(auto &x:nums)
        {
            Num_Xor^=x;
        }
        return Num_Xor;
    }
};