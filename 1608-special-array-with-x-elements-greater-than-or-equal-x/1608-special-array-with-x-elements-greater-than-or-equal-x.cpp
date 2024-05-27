class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=1;i<=1000;i++)
        {
            int indx=lower_bound(nums.begin(),nums.end(),i)-nums.begin();
            if(n-indx==i)
                return i;
        }
        return -1;
    }
};