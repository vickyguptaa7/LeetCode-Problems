class Solution {
public:

    bool check(int k,vector<int>&tasks,vector<int>&workers,int pills, int strength)
    {
        multiset<int>w(workers.begin(),workers.begin()+k);
        for(int i=k-1;i>=0;i--)
        {
            auto it=w.lower_bound(tasks[i]);
            if(it==w.end())
            {
                if(pills)
                {
                    it=w.lower_bound(tasks[i]-strength);
                    pills--;
                    if(it==w.end())
                        return false;
                    w.erase(w.find(*it));
                }
                else
                {
                    return false;
                }
            }
            else
            {
                w.erase(w.find(*it));
            }
        }
        return true;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(),tasks.end());
        sort(workers.rbegin(),workers.rend());
        int ans=0,lo=0,hi=min(tasks.size(),workers.size());
        while(lo<=hi)
        {
            int mid=(lo+hi)/2;
            if(check(mid,tasks,workers,pills,strength))
            {
                ans=mid;
                lo=mid+1;
            }
            else
            {
                hi=mid-1;
            }
        }
        return ans;
    }
};