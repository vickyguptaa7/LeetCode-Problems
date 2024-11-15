class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n=arr.size();
        int left=0;
        for(int i=1;i<n;i++)
        {
            if(arr[i-1]>arr[i])break;
            left=i;
        }
        if(left==n-1)
            return 0;
        int ans=left+1,prev=1e9;
        for(int i=n-1;i>=0;i--)
        {
            while(left>=0&&arr[left]>arr[i])
            {
                left--;
            }
            if(prev<arr[i])
                break;
            ans=max(ans,left+1+n-i);
            // cout<<left+1+n-i<<"\n";
            prev=arr[i];
        }
        return n-ans;
    }
};