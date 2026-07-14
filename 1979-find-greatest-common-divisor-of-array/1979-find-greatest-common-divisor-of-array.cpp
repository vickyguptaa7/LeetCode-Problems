class Solution {
public:

    int gcd(int a,int b)
    {
        if(b<=0)
            return a;
        return gcd(b,abs(a-b));
    }

    int findGCD(vector<int>& nums) {
        int mn = min_element(nums.begin(),nums.end())-nums.begin();
        int mx = max_element(nums.begin(),nums.end())-nums.begin();
        return gcd(nums[mx],nums[mn]);
    }
};
// 4,2 -> 2,2 -> 2,0 -> 2
// 3,2 -> 2,1 -> 1,1 -> 1
// 10,2 -> 2,8 -> 8,2 -> 2,6 -> 6,4 -> 4, 2