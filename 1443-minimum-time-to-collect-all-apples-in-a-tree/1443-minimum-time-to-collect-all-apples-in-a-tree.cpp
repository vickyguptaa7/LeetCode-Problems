class Solution {
public:
    
    bool helper(int src,vector<int>list[],vector<int>&visit,
               vector<bool>&hasApple,int &time)
    {
        visit[src]=true;
        bool isTrue=false;
        for(auto curr:list[src])
        {
            if(!visit[curr])
            {
                isTrue|=helper(curr,list,visit,hasApple,time);
            }
        }
        if(isTrue)
        {
            time++;
            return true;
        }
        if(hasApple[src])
        {
            time++;
            return true;
        }
        return false;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int>list[n];
        for(auto x:edges)
        {
            list[x[0]].push_back(x[1]);
            list[x[1]].push_back(x[0]);
        }
        vector<int>visit(n,false);
        int time=0;
        helper(0,list,visit,hasApple,time);
        return max((time-1)*2,0);
    }
};