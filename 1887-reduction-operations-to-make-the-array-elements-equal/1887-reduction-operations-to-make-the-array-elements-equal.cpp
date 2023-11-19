class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        map<int,int>freq;
        for(auto &num:nums)freq[num]++;
        int oper=0,count=0;
        for(auto iter=freq.rbegin();iter!=freq.rend();iter++)
        {
            count+=iter->second;
            oper+=count;
        }
        return oper-count;
    }
};