class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int>result;
        sort(nums.begin(),nums.end());
        for(auto x:queries)
        {
            int sum=x,cntr=0;
            for(auto y:nums)
            {
                if(sum>=y)
                {
                    sum-=y;
                    cntr++;
                }
                else 
                    break;
            }
            result.push_back(cntr);
        }
        return result;
    }
};