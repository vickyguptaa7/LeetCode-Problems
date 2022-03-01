class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++)
        {
            int temp=i;
            int count=0;
            while(temp>0)
            {
                if(temp%2==1)count++;
                temp/=2;
            }
            ans.push_back(count);
        }
        return ans;
    }
};