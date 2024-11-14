class Solution {
public:
    
    bool check(int mid,int n,vector<int>&quant)
    {
        for(int i=0;i<quant.size();i++)
        {
            n-=ceil(quant[i]/(long double)mid);
        }
        return n>=0;
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