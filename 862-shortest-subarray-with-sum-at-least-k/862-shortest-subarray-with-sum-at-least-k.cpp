class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<pair<int,long long>>dque;
        long long sum=0;
        int res=1e9;
        
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum>=k)
                res=min(res,i+1);
            
            pair<int,long long>curr={INT_MIN,INT_MIN};
            while(!dque.empty()&&(sum-dque.front().second>=k))
            {
                curr=dque.front();
                dque.pop_front();
            }
            
            if(curr.first!=INT_MIN)
                res=min(res,i-curr.first);
            
            while(!dque.empty()&&dque.back().second>=sum)
                dque.pop_back();
            
            dque.push_back({i,sum});
                
        }
        return res==1e9?-1:res;
    }
};