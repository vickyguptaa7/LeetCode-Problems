class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int low=1,high=n*m,ans=0;
        while(low<=high)
        {
            int mid=(high+low)/2;
            int cnt=0;
            for(int i=1;i<=n;i++)
            {
                cnt+=min(mid/i,m);
            }
            if(cnt>=k)
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