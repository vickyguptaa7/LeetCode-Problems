class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>umap;
        int n=nums.size();
        int prefix_sum=0;
        int subarray_count=0;
        for(int i=0;i<n;i++)
        {
            prefix_sum+=nums[i];
            if(umap.find(prefix_sum-k)!=umap.end())
            {
                subarray_count+=umap[prefix_sum-k];
            }
            umap[prefix_sum]++;
            if(k==prefix_sum)
            {
                subarray_count++;
            }
        }
        return subarray_count++;
    }
};