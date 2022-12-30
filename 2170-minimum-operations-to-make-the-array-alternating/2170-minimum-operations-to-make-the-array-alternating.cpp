typedef pair<int,int> ppi;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        if(nums.size()==1)
            return 0;
        map<int,int>freq1,freq2;
        for(int i=0;i<nums.size();i++)
        {
            if(i&1)
            {
                freq2[nums[i]]++;
            }
            else
            {
                freq1[nums[i]]++;
            }
        }
        int even=(nums.size()+1)/2;
        priority_queue<ppi,vector<ppi>,greater<ppi>>pque1,pque2;
        for(auto x:freq1)
        {
            int cost=even-x.second;
            pque1.push({cost,x.first});
        }
        for(auto x:freq2)
        {
            int cost=(int)nums.size()-even-x.second;
            pque2.push({cost,x.first});
        }
        vector<ppi>v1,v2;
        int k=5;
        while(!pque1.empty()&&k!=0)
        {
            k--;
            v1.push_back(pque1.top());
            pque1.pop();
        }
        k=5;
        while(!pque2.empty()&&k!=0)
        {
            k--;
            v2.push_back(pque2.top());
            pque2.pop();
        }
        int minCost=1e9;
        for(int i=0;i<v1.size();i++)
        {
            for(int j=0;j<v2.size();j++)
            {
                if(v1[i].second==v2[j].second)
                    continue;
                // cout<<v1[i].second<<" "<<v1[i].first<<"\n";
                // cout<<v2[j].second<<" "<<v2[j].first<<"\n\n";
                
                minCost=min(minCost,v1[i].first+v2[j].first);
            }
        }
        return minCost==1e9?(nums.size()/2):minCost;
    }
};