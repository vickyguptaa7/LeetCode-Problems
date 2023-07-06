class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        map<int,int>preIndx;
        int sum=0,size=1e9;
        preIndx[0]=-1;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            auto curr=preIndx.upper_bound(sum-target);
            if(curr!=preIndx.begin())
            {
                curr=prev(curr);
                size=min(size,i-curr->second);
            }
            preIndx[sum]=i;
        }
        return size==1e9?0:size;
    }
};