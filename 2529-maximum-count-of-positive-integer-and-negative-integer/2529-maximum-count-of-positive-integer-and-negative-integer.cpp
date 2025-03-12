class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int lindx=lower_bound(nums.begin(),nums.end(),0)-nums.begin();
        int rindx=upper_bound(nums.begin(),nums.end(),0)-nums.begin();
        cout<<lindx<<" "<<rindx<<"\n";
        return max((int)nums.size()-rindx,lindx);
    }
};