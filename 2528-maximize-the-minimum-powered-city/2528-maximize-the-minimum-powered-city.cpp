class Solution {
public:
    
    long long check(long long ans,vector<int>&stations,int r)
    {
        deque<pair<int,long long>>dque;
        int n=stations.size();
        long long sum=0;
        long long oper=0;
        for(int i=0;i<=r;i++)
        {
            sum+=stations[i];
            dque.push_back({i,stations[i]});
        }
        for(int i=0;i<n;i++)
        {
            if(sum<ans)
            {   
                oper+=(ans-sum);
                dque.back().second+=(ans-sum);
                sum+=(ans-sum);
            }
            if(i-dque.front().first>=r)
            {
                sum-=dque.front().second;
                dque.pop_front();
            }
            if(i+r+1<n)
            {
                sum+=stations[i+r+1];
                dque.push_back({i+r+1,stations[i+r+1]});
            }
        }
        return oper;
    }
    
    long long maxPower(vector<int>& stations, int r, int k) {
        long long low=0,high=1e14;
        long long res=0;
        while(low<=high)
        {
            long long mid=low+(high-low)/2;
            if(check(mid,stations,r)<=k)
            {
                low=mid+1;
                res=mid;
            }
            else
            {
                high=mid-1;
            }
        }
        return res;
    }
};