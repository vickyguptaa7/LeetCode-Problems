class Solution {
public:
    
    bool isValid(int cap,vector<int>&weights,int days)
    {
        int bag=0;
        for(auto x:weights)
        {
            bag+=x;
            if(bag>cap)
            {
                bag=x;
                if(bag>cap)
                    return false;
                days--;
            }
        }
        return days>0;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int low=0,high=1e9,ans=0;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(isValid(mid,weights,days))
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