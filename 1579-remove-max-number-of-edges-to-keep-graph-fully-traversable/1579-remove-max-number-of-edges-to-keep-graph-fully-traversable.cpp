class DisjSet
{
    int *parent;
    int *rank;
    int size;

public:
    DisjSet(int capacity)
    {
        size = capacity;
        parent = new int[size];
        rank = new int[size];
        initializer();
    }
    void initializer()
    {
        for (int i = 0; i < size; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int Find(int x)
    {
        if (parent[x] == x)
            return x;
        parent[x]=Find(parent[x]);
        return parent[x];
    }
    void Union(int x, int y)
    {
        int x_rep = Find(x);
        int y_rep = Find(y);

        if (x_rep == y_rep)
            return;
        if (rank[x_rep] > rank[y_rep])
            parent[y_rep] = x_rep;
        else if (rank[y_rep] > rank[x_rep])
            parent[x_rep] = y_rep;
        else
        {
            parent[y_rep] = x_rep;
            rank[x_rep]++;
        }
    }
}; 

bool mycomp(vector<int>&a,vector<int>&b)
{
    return a[0]>b[0];
}

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(),edges.end(),mycomp);
        DisjSet d1(n+1),d2(n+1);
        int i=0;
        int del1=0,del2=0;
        for(i=0;i<edges.size();i++)
        {
            if(edges[i][0]==3)
            {
                if(d1.Find(edges[i][1])==d2.Find(edges[i][2]))
                {
                    del1++;
                    continue;
                }
                d1.Union(edges[i][1],edges[i][2]);
                d2.Union(edges[i][1],edges[i][2]);
            }
            else if(edges[i][0]==1)
            {
                if(d1.Find(edges[i][1])==d1.Find(edges[i][2]))
                {
                    del1++;
                }
                else 
                {
                    d1.Union(edges[i][1],edges[i][2]);
                }
            }
            else 
            {
                if(d2.Find(edges[i][1])==d2.Find(edges[i][2]))
                {
                    del2++;
                }
                else 
                {
                    d2.Union(edges[i][1],edges[i][2]);
                }
            }
        }
        int par=d1.Find(1);
        for(int i=1;i<=n;i++)
        {
            if(par!=d1.Find(i))
                return -1;
        }
        par=d2.Find(1);
        for(int i=1;i<=n;i++)
        {
            if(par!=d2.Find(i))
                return -1;
        }
        return del1+del2;
    }
};