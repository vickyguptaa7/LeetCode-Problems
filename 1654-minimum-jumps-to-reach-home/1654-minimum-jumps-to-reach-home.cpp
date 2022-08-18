class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        int lsize=6005;
        vector<bool>visit(lsize,false);
        for(auto x:forbidden)visit[x]=true;
        
        queue<pair<int,bool>>que;
        que.push({0,false});
        int cnt=0;
        visit[0]=true;

        while(!que.empty())
        {
            int size=que.size();
            while(size--)
            {
                auto curr=que.front();
                que.pop();
                
                if(curr.first==x)return cnt;
                
                int newPos=curr.first+a;
                if(newPos<lsize&&!visit[newPos])
                {
                    que.push({newPos,false});
                    visit[newPos]=true;
                }
                
                newPos=curr.first-b;
                if(!curr.second&&newPos>0&&!visit[newPos])
                {
                    que.push({newPos,true});
                }
            }
            cnt++;
        }
        return -1;
    }
};