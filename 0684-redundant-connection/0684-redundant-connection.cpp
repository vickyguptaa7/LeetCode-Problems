
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

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DisjSet uf(edges.size());
        for(auto x:edges)
        {
            if(uf.Find(x[0]-1)==uf.Find(x[1]-1))
            {
                return {x[0],x[1]};
            }
            uf.Union(x[0]-1,x[1]-1);
        }
        return {0,0};
    }
};