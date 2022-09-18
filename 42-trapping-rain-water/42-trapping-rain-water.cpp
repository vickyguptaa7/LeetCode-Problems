class Solution {
public:
    int trap(vector<int>& height) {
        int height_len=height.size();
        vector<int>leftmost_greater(height_len,0),rightmost_greater(height_len,0);
        int Max=0;
        for(int i=0;i<height_len;i++)
        {
            Max=max(Max,height[i]);
            leftmost_greater[i]=Max;
        }
        Max=0;
        for(int i=height_len-1;i>=0;i--)
        {
            Max=max(Max,height[i]);
            rightmost_greater[i]=Max;
        }
        int water_trap=0;
        for(int i=1;i<height_len-1;i++)
        {
            water_trap+=max(min(leftmost_greater[i-1],rightmost_greater[i+1])-height[i],0);
        }
        return water_trap;
    }
};