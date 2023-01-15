class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int>result;
        int size=nums[0].size();
        for(auto x:queries)
        {
            int ki=x[0],trim=x[1];
            priority_queue<pair<string,int>>pque;
            for(int i=0;i<nums.size();i++)
            {
                pque.push({nums[i].substr(size-trim),i});
                if(pque.size()>ki)
                {
                    pque.pop();
                }
            }
            result.push_back(pque.top().second);
        }
        return result;
    }
};