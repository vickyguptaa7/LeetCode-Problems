class Solution {
public:
    
    bool check(int mid,vector<int>&bloomDay,int m,int k)
    {
        int curr=0,n=bloomDay.size();
        for(int i=0;i<n;i++)
        {
            if(bloomDay[i]<=mid)
            {
                curr++;
                if(curr==k)
                {
                    m--;
                    if(m==0)
                        return true;
                    curr=0;
                }
            }
            else
            {
                curr=0;
            }
        }
        return false;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low=0,high=1e9,ans=-1;
        while(low<=high)
        {
            int mid=low+((high-low)/2);
            if(check(mid,bloomDay,m,k))
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