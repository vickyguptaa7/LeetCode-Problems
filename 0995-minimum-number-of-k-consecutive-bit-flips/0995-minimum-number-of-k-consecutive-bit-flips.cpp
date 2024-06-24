class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        queue<int>que;
        int oper=0;
        for(int i=0;i<nums.size();i++)
        {
            while(!que.empty()&&i>=que.front())
            {
                que.pop();
            }
            int curr=nums[i]+que.size();
            if(curr&1)continue;
            oper++;
            if(i+k>nums.size())
                return -1;
            que.push(i+k);
        }
        return oper;
    }
};