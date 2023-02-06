class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>result(n*2,0);
        for(int i1=0,i2=0,i3=n;i1<n*2;i1+=2,i2++,i3++)
        {
            result[i1]=nums[i2];
            result[i1+1]=nums[i3];
        }
        return result;
    }
};