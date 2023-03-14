class Solution {
public:
    
    int isValid(int mid,vector<int>&candies,long long k)
    {
        if(mid==0)
            return true;
        for(auto x:candies)
        {
            k-=x/mid;
        }
        return k<=0;
    }
    
    int maximumCandies(vector<int>& candies, long long k) {
        int low=0,high=1e7,ans=0;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(isValid(mid,candies,k))
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