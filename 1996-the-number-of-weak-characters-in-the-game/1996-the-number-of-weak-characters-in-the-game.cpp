bool mycomp(vector<int>&a,vector<int>&b)
{
    if(a[0]!=b[0])return a[0]>b[0];
    return a[1]>b[1];
}

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& prop) {
        sort(prop.begin(),prop.end(),mycomp);
        vector<int>curr=prop[0],next={-1,0};
        int res=0;
        
        for(auto x:prop)
        {
            if(next[0]!=-1&&x[0]!=next[0])
            {
                curr=next;
                next={-1,0};
            }
            if(x[0]<curr[0]&&x[1]<curr[1])
            {
                res++;
            }
            if(x[1]>curr[1])
            {
                if(next[0]==-1||(next[0]!=-1&&next[1]<x[1]))
                next=x;
            }
        }
        return res;
    }
};