class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int,int>freq;
        for(auto x:answers)
            freq[x]++;
        
        int result=0;
        
        for(auto x:freq)
        {
            int factor=ceil(x.second/(long double)(x.first+1));
            result+=(x.first+1)*factor;
        }
        return result;
    }
};