class Solution {
public:
    int countLargestGroup(int n) {
        vector<int>freq(40);
        int mx=0,ans=0;
        for(int i=1;i<=n;i++)
        {
            int temp=i,sum=0;
            while(temp)
            {
                sum+=temp%10;
                temp/=10;
            }
            freq[sum]++;
            mx=max(mx,freq[sum]);
        }
        for(auto f:freq)
            ans+=mx==f;
        return ans;
    }
};