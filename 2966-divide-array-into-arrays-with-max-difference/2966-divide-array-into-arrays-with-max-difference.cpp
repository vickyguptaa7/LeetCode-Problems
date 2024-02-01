class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        for(int i=0;i<nums.size();i+=3)
        {
            vector<int>temp={nums[i]};
            for(int j=i+1;j<i+3;j++)
            {
                if(nums[j]-temp.front()>k)
                    return {};
                temp.push_back(nums[j]);
            }
            res.push_back(temp);
        }
        return res;
    }
};