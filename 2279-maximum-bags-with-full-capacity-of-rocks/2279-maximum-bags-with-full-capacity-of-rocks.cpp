class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int>remaining;
        for(int i=0;i<rocks.size();i++)
        {
            remaining.push_back(capacity[i]-rocks[i]);
        }
        sort(remaining.begin(),remaining.end());
        int result=0;
        for(auto x:remaining)
        {
            if(x==0)
                result++;
            else if(x<=additionalRocks)
            {
                additionalRocks-=x;
                result++;
            }
            else
            {
                break;
            }
        }
        return result;
    }
};