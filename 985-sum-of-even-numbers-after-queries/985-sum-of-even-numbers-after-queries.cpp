class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>result;
        set<int>include;
        int sum=0,n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]&1)continue;
            sum+=nums[i];
            include.insert(i);
        }
        for(auto query:queries)
        {
            nums[query[1]]+=query[0];
            if(include.count(query[1]))
            {
                
                if(nums[query[1]]&1)
                {
                    sum-=(nums[query[1]]-query[0]);
                    include.erase(query[1]);
                }
                else
                {
                    sum+=query[0];
                }
            }
            else if(!(nums[query[1]]&1)) 
            {
                include.insert(query[1]);
                sum+=nums[query[1]];
            }
            result.push_back(sum);
        }
        return result;
    }
};