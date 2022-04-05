class Solution {
public:
    int maxArea(vector<int>& height) {
        int low=0,high=height.size()-1;
        int result=0;
        while(low<high)
        {
            int area=(high-low)*min(height[low],height[high]);
            result=max(result,area);
            if(height[low]>height[high])
            {
                high--;
            }
            else
            {
                low++;
            }
        }
        return result;
    }
};