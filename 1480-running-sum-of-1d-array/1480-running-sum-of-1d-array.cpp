class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>res;
        int sum=0;
        for(auto x:nums)
        {
            sum+=x;
            res.push_back(sum);
        }
        return res;
    }
};