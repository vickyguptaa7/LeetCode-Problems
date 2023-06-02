class Solution {
public:
    
    int helper(int src,vector<int>list[],vector<int>&visit,vector<int>&nodeCnt)
    {
        int cnt=0;
        visit[src]=true;
        for(auto child:list[src])
        {
            if(!visit[child])
            {
                cnt+=helper(child,list,visit,nodeCnt);
            }
        }
        return cnt+1;
    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        vector<int>list[n];
        for(int i=0;i<bombs.size();i++)
        {
            for(int j=0;j<bombs.size();j++)
            {
                if(i==j)
                    continue;
                long long x=(bombs[i][0]-bombs[j][0]+0ll)*(bombs[i][0]-bombs[j][0]);
                long long y=(bombs[i][1]-bombs[j][1]+0ll)*(bombs[i][1]-bombs[j][1]);
                long long r=bombs[i][2]*1ll*bombs[i][2]; 
                if(x+y<=r)
                {
                    list[i].push_back(j);
                }
            }
        }
        vector<int>nodes(n,0);
        int result=1;
        for(int i=0;i<n;i++)
        {
            vector<int>visit(n,0);
            result=max(result,helper(i,list,visit,nodes));
        }
        return result;
    }
};