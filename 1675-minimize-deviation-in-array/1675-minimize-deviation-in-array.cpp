class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n=nums.size(),min_ele=1e9;
        for(int i=0;i<n;i++)
        {
            if(nums[i]&1)
            {
                nums[i]*=2;
            }
            min_ele=min(min_ele,nums[i]);
        }
        priority_queue<int>pq(nums.begin(),nums.end());
        int min_diff=1e9;
        while(pq.top()%2==0)
        {
            int curr=pq.top();
            pq.pop();
            min_diff=min(min_diff,curr-min_ele);
            min_ele=min(min_ele,curr/2);
            curr/=2;
            pq.push(curr);
        }
        min_diff=min(min_diff,pq.top()-min_ele);
        return min_diff;
    }
};