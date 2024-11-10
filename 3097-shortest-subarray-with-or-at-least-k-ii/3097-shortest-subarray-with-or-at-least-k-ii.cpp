class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<int>arr(32,0);
        long long res=0;
        int tail=0,head=-1,len=1e9,n=nums.size();
        while(head<n)
        {
            while(head+1<n&&res<k)
            {
                head++;
                for(int i=0;i<31;i++)
                {
                    arr[i]+=!!(nums[head]&(1<<i));
                    res|=(nums[head]&(1<<i));
                }
                if (res >= k)
                break;
            }
            if(res>=k)
            {
                len=min(len,head-tail+1);
            }
            if(tail>head)
            {
                tail++;
                head=tail-1;
            }
            else
            {
                for(int i=0;i<31;i++)
                {
                    if((nums[tail]&(1<<i)))
                    {
                        arr[i]--;
                        if(arr[i]==0)
                        {
                            res=(res&(~(1<<i)));
                        }
                    }
                }
                tail++;
            }
        }
        if (len == 0)
        return 1;
        return len==1e9?-1:len;
    }
};