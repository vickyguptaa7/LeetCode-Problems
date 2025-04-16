class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long ans=0;
        map<int,int>freq;
        int head=-1,tail=0,n=nums.size();
        long long count=0;
        while(tail<n)
        {
            while(head+1<n&&count<k)
            {
                head++;
                count+=freq[nums[head]];
                freq[nums[head]]++;
            }
            if(count>=k)
            {
                ans+=n-head;
            }
            if(tail>head)
            {
                head=tail;
            }
            else
            {
                freq[nums[tail]]--;
                count-=freq[nums[tail]];
                tail++;
            }
        }
        return ans;
    }
};