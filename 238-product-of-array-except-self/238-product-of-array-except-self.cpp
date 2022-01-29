class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>result(n+1);
        result[n]=1;
        int pre_product=1;
        for(int i=n-1;i>=0;i--)
        {
            pre_product*=nums[i];
            result[i]=pre_product;
        }
        pre_product=1;
        for(int i=0;i<n;i++)
        {
            result[i]=pre_product*result[i+1];
            pre_product*=nums[i];
        }
        result.pop_back();
        return result;
    }
};