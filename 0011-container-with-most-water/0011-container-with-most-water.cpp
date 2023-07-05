class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0,right=height.size()-1,result=0;
        while(left<right)
        {
            result=max(result,min(height[left],height[right])*(right-left));
            if(height[left]>height[right])
            {
                right--;
            }
            else
            {
                left++;
            }
        }
        return result;
    }
};