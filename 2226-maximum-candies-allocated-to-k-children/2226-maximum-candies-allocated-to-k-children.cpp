class Solution {
public:

    bool check(vector<int>& candies, long long k,int mid)
    {
        if(mid==0)
            return true;
        for(int i=0;i<candies.size();i++)
        {
            k-=candies[i]/mid;
            if(k<=0)
                return true;
        }
        return false;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int low=0,high=*max_element(candies.begin(),candies.end());
        int ans=0;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(check(candies,k,mid))
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