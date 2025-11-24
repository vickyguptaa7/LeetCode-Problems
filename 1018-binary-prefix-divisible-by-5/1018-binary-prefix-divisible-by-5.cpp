class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool>res;
        int sum=0;
        for(auto num:nums)
        {
            sum=sum*2+num;
            sum%=5;
            res.push_back(sum==0);
        }
        return res;
    }
};