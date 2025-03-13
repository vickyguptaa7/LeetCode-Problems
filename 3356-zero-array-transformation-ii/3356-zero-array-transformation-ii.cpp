class Solution {
public:

    bool check(vector<int>& nums, vector<vector<int>>& queries,int k)
    {
        vector<int>arr(nums.size(),0);
        for(int i=0;i<k;i++)
        {
            arr[queries[i][0]]+=queries[i][2];
            if(queries[i][1]+1<arr.size())
                arr[queries[i][1]+1]-=queries[i][2];
        }
        for(int i=0;i<arr.size();i++)
        {
            arr[i]=(i==0?arr[i]:arr[i]+arr[i-1]);
            if(arr[i]<nums[i])
                return false;
        }
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int low=0,high=queries.size(),ans=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(check(nums,queries,mid))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};