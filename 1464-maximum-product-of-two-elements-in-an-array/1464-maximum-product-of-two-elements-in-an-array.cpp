class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx1=0,mx2=0;
        for(auto num:nums)
        {
            if(num>mx1)
            {
                mx2=mx1;
                mx1=num;
            }
            else
            {
                mx2=max(mx2,num);
            }
        }
        return (mx1-1)*(mx2-1);
    }
};