typedef pair<int,int> ppi;

struct Mycomp{
    bool operator()(ppi &p1,ppi &p2)
    {
        if(p1.first!=p2.first)
            return p1.first<p2.first;
        
        return p1.second>p2.second;
    }
};

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        priority_queue<ppi ,vector<ppi>,Mycomp>pque;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
                    queue<ppi>que;
                    while(!pque.empty()&&pque.top().first+1>nums[i])
                    {
                        que.push(pque.top());
                        pque.pop();
                    }
                    if(!pque.empty()&&pque.top().first+1==nums[i])
                    {
                        auto temp=pque.top();
                        pque.pop();
                        pque.push({nums[i],temp.second+1});
                    }
                    else 
                    {
                        pque.push({nums[i],1});
                    }
                    while(!que.empty())
                    {
                        pque.push(que.front());
                        que.pop();
                    }
        }
        while(!pque.empty())
        {
            // cout<<pque.top().first<<" "<<pque.top().second<<"\n";
            if(pque.top().second<3)return false;
            pque.pop();
        }
        return true;
    }
};