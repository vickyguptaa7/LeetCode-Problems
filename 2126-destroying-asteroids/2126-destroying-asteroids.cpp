class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& astrd) {
        sort(astrd.begin(),astrd.end());
        long long sum=mass;
        for(auto x:astrd)
        {
            if(sum>=x)
            {
                sum+=x;
            }
            else 
            {
                return false;
            }
        }
        return true;
    }
};