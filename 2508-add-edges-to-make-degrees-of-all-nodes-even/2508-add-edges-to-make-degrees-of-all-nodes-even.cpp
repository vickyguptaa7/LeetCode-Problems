class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<int>edgeCount(n+1,0);
        set<int>list[n+1];
        for(auto x:edges)
        {
            edgeCount[x[0]]++;
            edgeCount[x[1]]++;
            list[x[0]].insert(x[1]);
            list[x[1]].insert(x[0]);
        }
        vector<int>oddEdge;
        int edgeNo=0;
        for(auto x:edgeCount)
        {
            if(x&1)
            {
                oddEdge.push_back(edgeNo);
                if(x==n-1)
                    return false;
            }
            edgeNo++;
        }
        if(oddEdge.size()&1||oddEdge.size()>4)
            return false;
        if(oddEdge.size()==4)
        {
            if(!list[oddEdge[0]].count(oddEdge[1])&&
              !list[oddEdge[3]].count(oddEdge[2]))
                return true;
            if(!list[oddEdge[0]].count(oddEdge[2])&&
              !list[oddEdge[1]].count(oddEdge[3]))
                return true;
            if(!list[oddEdge[0]].count(oddEdge[3])&&
              !list[oddEdge[1]].count(oddEdge[2]))
                return true;
            return false;
        }
        else if(oddEdge.size()==2&&list[oddEdge[0]].count(oddEdge[1]))
        {
            for(int i=1;i<=n;i++)
            {
                if(!list[i].count(oddEdge[0])&&!list[i].count(oddEdge[1]))
                {
                    return true;
                }
            }
            return false;
        }
            
        return true;
        
    }
};