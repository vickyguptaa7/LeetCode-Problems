class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>rightMax(height.size(),0);
        int n=height.size(),mx=0;
        for(int i=n-1;i>=0;i--)
        {
            mx=max(mx,height[i]);
            rightMax[i]=mx;
        }
        mx=height[0];
        int water=0;
        for(int i=1;i<n-1;i++)
        {
            water+=max(0,min(mx,rightMax[i+1])-height[i]);
            mx=max(mx,height[i]);
        }
        return water;
    }
};