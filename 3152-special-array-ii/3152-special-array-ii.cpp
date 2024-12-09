class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>fault;
        for(int i=1;i<nums.size();i++)
        {
            if((nums[i]&1)==(nums[i-1]&1))
            {
                fault.push_back(i-1);
            }
        }
        vector<bool>res;
        for(int i=0;i<queries.size();i++)
        {
            int l=queries[i][0],r=queries[i][1];
            int indx=lower_bound(fault.begin(),fault.end(),l)-fault.begin();
            if(indx==fault.size()||fault[indx]>=r)
                res.push_back(true);
            else
                res.push_back(false);
        }
        return res;
    }
};