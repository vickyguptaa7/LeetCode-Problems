class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int result=0;
        int mask=0;
        unordered_set<int>prefixs;
        for(int i=30;i>=0;i--)
        {
            mask=mask|(1<<i);
            for(auto num:nums)
            {
                prefixs.insert(num&mask);
            }
            int temp=result|(1<<i);
            for(auto prefix:prefixs)
            {
                if(prefixs.count(prefix^temp))
                {
                    result=temp;
                    break;
                }
            }
            prefixs.clear();
        }
        return result;
    }
};