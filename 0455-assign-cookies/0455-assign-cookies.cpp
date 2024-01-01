class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int count=0,itr=0;
        for(int i=0;i<g.size();i++)
        {
            int sum=0;
            while(sum<g[i]&&itr<s.size())
            {
                sum=s[itr++];
            }
            if(sum>=g[i])
                count++;
            else
                break;
        }
        return count;
    }
};