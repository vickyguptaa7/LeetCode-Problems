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
    int find(int x)
    {
        if (parent[x] == x)
            return x;
        parent[x]=find(parent[x]);
        return parent[x];
    }
    void Union(int x, int y)
    {
        int x_rep = find(x);
        int y_rep = find(y);

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
    bool equationsPossible(vector<string>& equations) {
        DisjSet equal(26);
        for(auto eq:equations)
        {
            if(eq[1]=='=')
                equal.Union(eq[0]-'a',eq[3]-'a');
        }
        for(auto eq:equations)
        {
            if(eq[1]=='!'&&equal.find(eq[0]-'a')==equal.find(eq[3]-'a'))
                return false;
        }
        return true;
    }
};