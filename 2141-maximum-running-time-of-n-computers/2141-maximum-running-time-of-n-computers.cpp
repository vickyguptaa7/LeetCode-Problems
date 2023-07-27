class Solution {
public:
    
    bool isValid(int n,vector<int>&bat,long long hrs)
    {
        long long time=0;
        for(auto x:bat)
        {
            time+=x;
            if(time>=hrs)
            {
                n--;
                time-=hrs;
            }
        }
        return n<=0;
    }
    
    long long maxRunTime(int n, vector<int>& batteries) {
        long long low=0,high=accumulate(batteries.begin(),batteries.end(),0ll)/n,ans=0;
        sort(batteries.begin(),batteries.end());
        while(low<=high)
        {
            long long mid=low+(high-low)/2;
            if(isValid(n,batteries,mid))
            {
                ans=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return ans;
    }
};