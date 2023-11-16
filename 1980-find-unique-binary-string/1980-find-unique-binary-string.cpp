class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string>oset(nums.begin(),nums.end());
        for(int i=0;i<17;i++)
        {
            string curr;
            int num=i;
            for(int j=0;j<nums[0].size();j++)
            {
                curr+=(num&1)?"1":"0";
                num/=2;
            }
            if(!oset.count(curr))
                return curr;
        }
        return "";
    }
};