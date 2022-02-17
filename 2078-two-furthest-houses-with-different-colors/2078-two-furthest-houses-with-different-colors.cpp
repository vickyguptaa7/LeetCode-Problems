class Solution {
public:
    int maxDistance(vector<int>& arr) {
        int n=arr.size();
        int result=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]!=arr[0])
            {
                result=max(result,i);
            }
            if(arr[n-1-i]!=arr[n-1])
            {
                result=max(result,i);
            }
        }
        return result;
    }
};