class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int maxValue=0,currValue=0,numsSum=0,size=nums.size();
        for(int i=0;i<size;i++)
        {
            currValue+=i*(nums[i]);
            numsSum+=nums[i];
        }
        maxValue=currValue;
        for(int i=0;i<size;i++)
        {
            currValue+=numsSum-nums[size-1-i]*size;
            maxValue=max(maxValue,currValue);
        }
        return maxValue;
    }
};
/*
add the array sum to the prev answer calculated because in next right rotation the index multiplied got increased by 1.
And the last element of the array should be subtracted bcoz it got to the first index and the value have to be decreased to get to the new state.
*/