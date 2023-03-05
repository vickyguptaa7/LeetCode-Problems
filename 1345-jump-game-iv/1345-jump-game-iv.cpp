class Solution {
public:
    int minJumps(vector<int>& arr) {
        map<int,set<int>>eleIndx;
        for(int i=0;i<arr.size();i++)eleIndx[arr[i]].insert(i);
        
        queue<int>que;
        que.push(0);
        vector<int>visited(arr.size(),0);
        visited[0]=true;
        int time=0;
        while(!que.empty())
        {
            int size=que.size();
            while(size--)
            {
                int indx=que.front();
                que.pop();
                if(indx+1==arr.size())
                    return time;
                
                if(indx+1<arr.size()&&!visited[indx+1])
                {
                    que.push(indx+1);
                    visited[indx+1]=true;
                }
                    
                if(indx-1>=0&&!visited[indx-1])
                {
                    que.push(indx-1);
                    visited[indx-1]=true;
                }
                for(auto x:eleIndx[arr[indx]])
                {
                    if(!visited[x])
                    {
                        visited[x]=true;
                        que.push(x);
                    }
                }
                eleIndx.erase(arr[indx]);
            }
            time++;
        }
        return time;
    }
};