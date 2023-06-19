class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int mxAlt=0,alt=0;
        for(auto g:gain)
        {
            alt+=g;
            mxAlt=max(mxAlt,alt);
        }
        return mxAlt;
    }
};