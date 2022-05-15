class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(),special.end());
        int maxRange=0,midd;
        for(int i=0;i<special.size();i++)
        {
            midd=special[i]-1;
            maxRange=max(midd-bottom+1,maxRange);
            bottom=special[i]+1;
        }
        maxRange=max(maxRange,top-special.back());
        return maxRange;
    }
};