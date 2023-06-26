class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        map<int,set<int>>first,last;
        int n=costs.size();
        for(int i=0;i<candidates;i++)first[costs[i]].insert(i);
        for(int i=n-candidates;i<n;i++)last[costs[i]].insert(i);
        int left=candidates,right=n-candidates-1;
        long long curr=0;
        while(k--)
        {
            if(!first.empty()&&(last.empty()||first.begin()->first<=last.begin()->first))
            {
                curr+=first.begin()->first;
                // cout<<first.begin()->first<<"\n";
                int indx=*first.begin()->second.begin();
                first.begin()->second.erase(indx);
                if(last.begin()->first==first.begin()->first)
                {
                    last.begin()->second.erase(indx);
                    if(last.begin()->second.empty())
                        last.erase(last.begin()->first);
                }
                if(first.begin()->second.empty())
                    first.erase(first.begin()->first);
                
                if(left<=right)
                {
                    first[costs[left]].insert(left);
                    left++;
                }
            }
            else 
            {
                curr+=last.begin()->first;
                // cout<<last.begin()->first<<"\n";
                int indx=*last.begin()->second.begin();
                last.begin()->second.erase(indx);
                if(last.begin()->first==first.begin()->first)
                {
                    first.begin()->second.erase(indx);
                    if(first.begin()->second.empty())
                        first.erase(first.begin()->first);
                }
                
                if(last.begin()->second.empty())
                    last.erase(last.begin()->first);
                
                if(left<=right)
                {
                    last[costs[right]].insert(right);
                    right--;
                }
            }
        }
        return curr;
    }
};