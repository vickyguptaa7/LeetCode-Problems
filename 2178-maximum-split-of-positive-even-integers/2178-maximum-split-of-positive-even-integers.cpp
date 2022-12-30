class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum&1)
            return {};
        vector<long long>result;
        for(int i=2;i<=finalSum;i+=2)
        {
            result.push_back(i);
            finalSum-=i;
        }
        result.back()+=finalSum;
        return result;
    }
};