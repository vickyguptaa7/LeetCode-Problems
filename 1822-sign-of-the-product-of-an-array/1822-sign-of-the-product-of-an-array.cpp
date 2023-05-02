class Solution {
public:
    int arraySign(vector<int>& nums) {
        int negCnt=0;
        for(auto &num:nums)
        {
            if(num==0)
                return 0;
            negCnt+=(num<0);
        }
        return negCnt&1?-1:1;
    }
};