bool mycomp(vector<int>&a,vector<int>&b)
{
    int opt1=min(-a[0],a[1]-a[0]-b[0]);
    int opt2=min(-b[0],b[1]-b[0]-a[0]);
    
    if(opt1==opt2)return a[0]>b[0];
    return opt1<opt2;
    
}
class Solution {
public:
    
    bool isValid(vector<vector<int>>&trans,long long init)
    {
        for(int i=0;i<trans.size();i++)
        {
            if(trans[i][0]>init)
            {
                return false;
            }
            init-=trans[i][0]-trans[i][1];
        }
        return true;
    }
    
    long long minimumMoney(vector<vector<int>>& trans) {
        sort(trans.begin(),trans.end(),mycomp);
        long long low=0,high=1e15,ans=0;
        while(low<=high)
        {
            long long mid=(low+high)/2;
            if(isValid(trans,mid))
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