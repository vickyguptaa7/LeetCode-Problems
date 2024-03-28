class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        int res=0,n=nums.size();
        int tail=0,head=-1;
        while(head<n)
        {
            while(head+1<n&&(!freq.count(nums[head+1])||freq[nums[head+1]]+1<=k))
            {
                head++;
                freq[nums[head]]++;
            }
            res=max(res,head-tail+1);
            if(tail>head)
            {
                tail++;
                head=tail-1;
            }
            else 
            {
                freq[nums[tail]]--;
                tail++;
            }
        }
        return res;
    }
};