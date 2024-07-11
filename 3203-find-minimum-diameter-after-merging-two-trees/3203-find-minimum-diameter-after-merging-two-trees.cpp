class Solution {
public:
    
    int diameterHelper(int src,int par,vector<int>list[],int& maxD)
    {
        int h1=0,h2=0;
        for(auto child:list[src])
        {
            if(child==par)continue;
            int h=diameterHelper(child,src,list,maxD);
            if(h1<h)
            {
                h2=h1;
                h1=h;
            }
            else
            {
                h2=max(h,h2);
            }
        }
        maxD=max(maxD,h1+h2+1);
        return 1+max(h1,h2);
    }
    
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n=1+edges1.size(),m=1+edges2.size();
        vector<int>list1[n],list2[m];
        for(auto edge:edges1)
        {
            list1[edge[0]].push_back(edge[1]);
            list1[edge[1]].push_back(edge[0]);
        }
        for(auto edge:edges2)
        {
            list2[edge[0]].push_back(edge[1]);
            list2[edge[1]].push_back(edge[0]);
        }
        int d1=0,d2=0;
        diameterHelper(0,-1,list1,d1);
        diameterHelper(0,-1,list2,d2);
    //         considering only edges not the nodes 
        d1--;
        d2--;
        return max({d1,d2,(d1+1)/2+1+(d2+1)/2});
    }
};