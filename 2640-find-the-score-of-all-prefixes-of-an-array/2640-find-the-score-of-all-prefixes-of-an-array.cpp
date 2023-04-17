class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<long long>score(nums.size(),0);
        int mxEle=nums[0];
        score[0]=2*nums[0];
        for(int i=1;i<nums.size();i++)
        {
            mxEle=max(mxEle,nums[i]);
            score[i]=nums[i]+mxEle;
            score[i]+=score[i-1];
        }
        return score;
    }
};