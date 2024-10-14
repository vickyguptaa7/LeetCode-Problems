class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>pque(nums.begin(),nums.end());
        long long ans=0;
        while(k--)
        {
            ans+=pque.top();
            int curr=pque.top();
            pque.pop();
            pque.push(ceil(curr/3.0));
        }
        return ans;
    }
};