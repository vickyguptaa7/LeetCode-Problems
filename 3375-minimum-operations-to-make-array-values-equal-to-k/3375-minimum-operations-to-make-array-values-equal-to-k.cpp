class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        map<int,int>freq;
        int mn=*min_element(nums.begin(),nums.end());
        for(auto x:nums)freq[x]++;
        if(mn<k)
            return -1;
        return mn==k?freq.size()-1:freq.size();
    }
};