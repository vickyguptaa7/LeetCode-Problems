class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum=0,val=1e9;
        int isNegC=0;
        for(auto &mat:matrix)
        {
            for(auto &x:mat)
            {
                sum+=abs(x);
                if(x<0)isNegC++;
                val=min(val,0ll+abs(x));
            }
        }
        return isNegC&1?sum-2*val:sum;
    }
};