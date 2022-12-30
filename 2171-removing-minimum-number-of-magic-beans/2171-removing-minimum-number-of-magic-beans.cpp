class Solution {
public:
    
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(),beans.end());
        vector<long long>preSum(beans.size()+1,0);
        for(int i=1;i<=beans.size();i++)
        {
            preSum[i]=preSum[i-1]+beans[i-1];
        }
        long long ans=1e18,n=beans.size(),remove=0;
        for(int i=0;i<beans.size();i++)
        {
            long long currAns=(preSum[n]-preSum[i])-(n-i)*beans[i]+remove;
            ans=min(currAns,ans);
            remove+=beans[i];
        }
        return ans;
    }
};