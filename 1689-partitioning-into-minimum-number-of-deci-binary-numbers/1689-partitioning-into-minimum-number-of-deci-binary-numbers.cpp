class Solution {
public:
    int minPartitions(string n) {
        int maxDig=0;
        for(auto x:n)
        {
            maxDig=max(maxDig,x-'0');
        }
        return maxDig;
    }
};