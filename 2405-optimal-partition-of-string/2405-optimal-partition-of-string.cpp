class Solution {
public:
    int partitionString(string s) {
        int isCharPresent=0,partitions=1;
        for(auto ch:s)
        {
            if(isCharPresent&(1<<(ch-'a')))
            {
                partitions++;
                isCharPresent=0;
            }
            isCharPresent|=(1<<(ch-'a'));
        }
        return partitions;
    }
};