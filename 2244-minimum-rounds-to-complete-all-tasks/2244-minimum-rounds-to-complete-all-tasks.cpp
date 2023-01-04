class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int>freq;
        for(auto x:tasks)
        {
            freq[x]++;
        }
        int rounds=0;
        for(auto x:freq)
        {
            if(x.second==1)
            {
                return -1;
            }
            int three=x.second/3;
            int left=x.second-three*3;
            int two=left/2;
            if(left%2!=0)
            {
                three--;
                two=(left+3)/2;
            }
            rounds+=two+three;
        }
        return rounds;
    }
};