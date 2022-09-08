bool mycomp(vector<int>&a,vector<int>&b)
{
    if(a[2]!=b[2])return a[2]<b[2];
    return a[1]<b[1];
}

class Solution {
public:
    
    bool isValid(vector<int>&chrg,vector<int>&rcst,long long budget,int k)
    {
        if(k==0)return true;
        long long cost=0;
        priority_queue<pair<int,int>>pque;
        for(int i=0;i<k;i++)
        {
            pque.push({chrg[i],i});
            cost+=rcst[i];
        }
        if(k!=0)
        if(cost*k+pque.top().first<=budget)return true;
        for(int i=k;i<chrg.size();i++)
        {
            cost-=rcst[i-k];
            cost+=rcst[i];
            pque.push({chrg[i],i});
            while(pque.top().second<=i-k)
            {
                pque.pop();
            }
            if(cost*k+pque.top().first<=budget)return true;
        }
        return false;
        
    }
    int maximumRobots(vector<int>& chrg, vector<int>& rcst, long long budget) {
        int high=chrg.size(),low=0,res=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(isValid(chrg,rcst,budget,mid))
            {
                res=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return res;
    }
};