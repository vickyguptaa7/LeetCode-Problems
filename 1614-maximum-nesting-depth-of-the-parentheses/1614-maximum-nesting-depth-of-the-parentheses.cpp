class Solution {
public:
    int maxDepth(string s) {
        int count=0,mxDepth=0;
        for(auto &ch:s)
        {
            if(ch=='(')count++;
            else if(ch==')')count--;
            mxDepth=max(mxDepth,count);
        }
        return mxDepth;
    }
};