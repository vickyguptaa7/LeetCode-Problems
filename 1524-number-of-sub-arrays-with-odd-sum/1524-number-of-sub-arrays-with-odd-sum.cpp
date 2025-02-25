class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int ans=0,even=1,odd=0,sum=0,mod=1e9+7;
        for(int i=0;i<arr.size();i++)
        {
            sum+=arr[i];
            even+=!(sum&1);
            odd+=(sum&1);
            if(sum&1)
            {
                ans+=even;
            }
            else
            {
                ans+=odd;
            }
            ans%=mod;
        }
        return ans;
    }
};