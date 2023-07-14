class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        map<int,int>mp;
        int ans=0;
        for(int i=0;i<arr.size();i++)
        {
            if(mp.count(arr[i]-difference))
            {
                mp[arr[i]]=mp[arr[i]-difference]+1;
            }
            else
            {
                mp[arr[i]]=1;    
            }
            ans=max(ans,mp[arr[i]]);
        }
        return ans;
    }
};