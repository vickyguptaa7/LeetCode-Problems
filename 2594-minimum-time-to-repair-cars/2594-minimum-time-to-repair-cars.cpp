class Solution {
public:

    bool check(vector<int>&ranks,int cars,long long time)
    {
        for(int i=0;i<ranks.size();i++)
        {
            long long r=time/ranks[i];
            cars-=(int)sqrt(r);
            if(cars<=0)
                return true;
        }
        return false;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long low=1,high=1e18,ans=0;
        while(low<=high)
        {
            long long mid=low+(high-low)/2;
            if(check(ranks,cars,mid))
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