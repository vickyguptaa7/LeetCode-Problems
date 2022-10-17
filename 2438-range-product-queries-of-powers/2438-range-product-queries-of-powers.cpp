class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<long long>binary;
        for(int i=0;i<32;i++)
        {
            if(n&(1ll<<i))
            {
                binary.push_back((1ll<<i));
            }
        }
        long long mod=1e9+7;
        vector<int>result;
        for(auto x:queries)
        {
            long long ans=1;
            for(int i=x[0];i<=x[1];i++)ans*=binary[i],ans%=mod;
            result.push_back(ans);
        }
        return result;
    }
};