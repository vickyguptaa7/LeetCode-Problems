class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int tail=0,head=-1,n=nums.size();
        unordered_set<int>d1(nums.begin(),nums.end());
        unordered_map<int,int>d2;
        int ans=0;
        while(tail<n)
        {
            while(head+1<n&&d2.size()!=d1.size())
            {
                head++;
                d2[nums[head]]++;
            }
            if(d2.size()!=d1.size())
            {
                break;
            }
            ans+=n-head;
            if(tail>head)
            {
                head=tail;
            }
            else
            {
                d2[nums[tail]]--;
                if(d2[nums[tail]]==0)
                    d2.erase(nums[tail]);
                tail++;
            }
        }
        return ans;
    }
};