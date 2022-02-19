class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int iterg=0,iters=0;
        int glen=g.size(),slen=s.size();
        int result=0;
        while(glen>iterg&&slen>iters)
        {
            if(g[iterg]<=s[iters])
            {
                iterg++;
                iters++;
                result++;
            }
            else
            {
                iters++;
            }
        }
        return result;
    }
};