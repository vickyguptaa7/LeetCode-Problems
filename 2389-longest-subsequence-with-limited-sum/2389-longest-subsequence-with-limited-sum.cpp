class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        map<int,int>msize;
        sort(nums.begin(),nums.end());
        vector<int>squery=queries;
        sort(squery.begin(),squery.end());
        int iter=0,sum=0;
        for(int i=0;i<nums.size()&&iter<squery.size();i++)
        {
            if(squery[iter]>=sum+nums[i])
            {
                sum+=nums[i];
            }
            else 
            {
                i--;
                msize[squery[iter++]]=i+1;
            }
        }
        while(iter<squery.size())
        {
            msize[squery[iter++]]=nums.size();
        }
        vector<int>res;
        for(auto x:queries)
        {
            res.push_back(msize[x]);
        }
        return res;
    }
};