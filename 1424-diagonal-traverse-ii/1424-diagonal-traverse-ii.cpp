class Solution {
public:
    
    void helper(int x,int y,vector<vector<int>>&nums,vector<int>&result,int size)
    {
        while(x>=0&&y<size)
        {
            if(nums[x].size()>y)
                result.push_back(nums[x][y]);
            x--;
            y++;
        }
    }
    
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<pair<long long,int>>dummy;
        long long cntr=1;
        for(int i=0;i<nums.size();i++)
        {
            long long strt=i+2,h=cntr;
            for(int j=0;j<nums[i].size();j++)
            {
                dummy.push_back({h,nums[i][j]});
                h+=strt;
                strt++;
            }
            cntr+=i+1;
        }
        sort(dummy.begin(),dummy.end());
        vector<int>res;
        for(auto d:dummy)res.push_back(d.second);
        return res;
    }
};