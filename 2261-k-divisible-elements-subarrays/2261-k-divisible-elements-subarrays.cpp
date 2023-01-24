class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>>vecSet;
        for(int i=0;i<nums.size();i++)
        {
            int _k=k;
            vector<int>sans;
            for(int j=i;j<nums.size();j++)
            {
                if(nums[j]%p==0)
                    _k--;
                sans.push_back(nums[j]);
                if(_k>=0)
                    vecSet.insert(sans);
            }
        }
        return vecSet.size();
    }
};