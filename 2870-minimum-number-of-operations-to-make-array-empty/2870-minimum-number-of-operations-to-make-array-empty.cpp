class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(auto &num:nums)freq[num]++;
        int oper=0;
        for(auto &num:freq)
        {
            if(num.second==1)
                return -1;
            oper+=(num.second)/3;
            if(num.second%3!=0)
                oper++;
        }
        return oper;
    }
};