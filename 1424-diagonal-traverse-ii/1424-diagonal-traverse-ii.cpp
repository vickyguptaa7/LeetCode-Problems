class Solution {
public:
    
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int,vector<int>>mmp;
        int size=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<nums[i].size();j++)
            {
                size=max(size,i+j);
                mmp[i+j].push_back(nums[i][j]);
            }
        }
        vector<int>res;
        for(int i=0;i<=size;i++)
        {
            if(!mmp.count(i))continue;
            vector<int>temp=mmp[i];
            int len=temp.size();
            for(int i=len-1;i>=0;i--)
            {
                res.push_back(temp[i]);
            }
        }
        return res;
    }
};