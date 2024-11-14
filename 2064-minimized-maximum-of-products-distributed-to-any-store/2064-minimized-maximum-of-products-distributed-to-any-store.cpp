class Solution {
public:
    
    bool check(int mid,int n,vector<int>&quant)
    {
        for(int i=0;i<quant.size();i++)
        {
            n-=(quant[i]+mid-1)/mid;
            if(n<0)
                return false;
        }
        return true;
    }
    
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low=1;
        int high=*max_element(quantities.begin(),quantities.end());
        int ans=1e9;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(check(mid,n,quantities))
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