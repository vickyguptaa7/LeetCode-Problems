class Solution {
public:
    
    long long tripCount(long long mid,vector<int>&time)
    {
        long long cntr=0;
        for(auto x:time)
        {
            cntr+=(mid/x);
        }
        return cntr;
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low=0,
        high=*min_element(time.begin(),time.end())*(long long)totalTrips,
        ans=0;
        while(low<=high)
        {
            long long mid=(low+high)/2;
            if(tripCount(mid,time)>=totalTrips)
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