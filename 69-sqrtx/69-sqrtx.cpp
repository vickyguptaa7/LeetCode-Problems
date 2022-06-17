class Solution {
public:
    int mySqrt(int x) {
        long long low=0,high=INT_MAX;
        int ans=0;
        while(low<=high)
        {
            long long mid=low+(high-low)/2;
            if(x>=mid*mid)
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