class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        priority_queue<int>pque(nums.begin(),nums.end());
        long long total_sum=accumulate(nums.begin(),nums.end(),0ll);

        int brek=0;
        while(target>0)
        {
            int curr=pque.top();
            pque.pop();
            total_sum-=curr;
            
            if(curr<=target)
                target-=curr;
            else if (curr>target&&total_sum<target)
            {
                brek++;
                total_sum+=curr;
                pque.push(curr/2);
                pque.push(curr/2);
            }
            if(pque.empty()&&target!=0)
                return -1;
        }
        return brek;
    }
};