class Solution {
public:
    int largestPerimeter(vector<int>& arr) {
        sort(arr.begin(),arr.end(),greater<int>());
        for(int i=2;i<arr.size();i++)
        {
            if(arr[i]+arr[i-1]>arr[i-2])
            {
                return arr[i-2]+arr[i-1]+arr[i];
            }
        }
        return 0;
    }
};