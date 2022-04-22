class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int>maxDeq,minDeq;
        int low=0,high=0,size=nums.size(),res=0;
        while(high<size)
        {
                           
            while(!minDeq.empty()&&nums[minDeq.front()]>=nums[high])
            {
                minDeq.pop_front();
            }

                minDeq.push_front(high);
            
            while(!maxDeq.empty()&&nums[maxDeq.front()]<=nums[high])
            {
                maxDeq.pop_front();
            }
                

                maxDeq.push_front(high);
               
            high++;
            if(nums[maxDeq.back()]-nums[minDeq.back()]>limit)
            {
               
                if(!minDeq.empty()&&minDeq.back()==low)
                {
                    minDeq.pop_back();
                }
                if(!maxDeq.empty()&&maxDeq.back()==low)
                {
                    maxDeq.pop_back();
                } 
                low++;
                 res=max(res,high-low);
            }
            
        }
        res=max(res,high-low);
        return res;
    }
};