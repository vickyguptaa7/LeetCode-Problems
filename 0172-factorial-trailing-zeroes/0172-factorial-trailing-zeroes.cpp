class Solution {
public:
    
    bool isValid(int mid,int n)
    {
        int cntr=0;
        while(n)
        {
            n/=5;
            cntr+=n;
        }
        return mid<=cntr;
    }
    int trailingZeroes(int n) {
        int low=0,high=5*n,ans=0;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(isValid(mid,n))
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