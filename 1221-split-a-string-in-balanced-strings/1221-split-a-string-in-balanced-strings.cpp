class Solution {
public:
    int balancedStringSplit(string s) {
        int result=0;
        int lcount=0,rcount=0;
        for(auto x:s)
        {
            if(x=='R')lcount++;
            else rcount++;
            
            if(lcount==rcount)result++;
        }
        return result;
    }
};