class Solution {
public:
    void moveInDir(int x,int y,int dir,vector<vector<int>>&visited)
    {
        int n=visited.size(),m=visited[0].size();
        while(x>=0&&x<n&&y>=0&&y<m&&visited[x][y]<2)
        {
            visited[x][y]=1;
            if(dir==0)
            {
                x++;
            }
            else if(dir==1)
            {
                x--;
            }
            else if(dir==2)
            {
                y++;
            }
            else
            {
                y--;
            }
        }
    }

    int countUnguarded(int n, int m, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<walls.size();i++)
        {
            visited[walls[i][0]][walls[i][1]]=3;
        }
        for(int i=0;i<guards.size();i++)
        {
            visited[guards[i][0]][guards[i][1]]=2;
        }
        for(int i=0;i<guards.size();i++)
        {
            moveInDir(guards[i][0]+1,guards[i][1],0,visited);
            moveInDir(guards[i][0]-1,guards[i][1],1,visited);
            moveInDir(guards[i][0],guards[i][1]+1,2,visited);
            moveInDir(guards[i][0],guards[i][1]-1,3,visited);
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<visited[i][j]<<" ";
                count+=visited[i][j]==0;
            }
            cout<<"\n";
        }
        return count;
    }
};