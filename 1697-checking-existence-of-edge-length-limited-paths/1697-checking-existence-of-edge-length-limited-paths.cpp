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
    return a[2]<b[2];
}

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, 
                                           vector<vector<int>>& queries) {
        sort(edgeList.begin(),edgeList.end(),mycomp);
        for(int i=0;i<queries.size();i++)
        {
            queries[i].push_back(i);
        }
        sort(queries.begin(),queries.end(),mycomp);
        DisjSet d(n);
        vector<pair<int,bool>>queryAnswer;
        int edgeIndx=0;
        for(int i=0;i<queries.size();i++)
        {
            while(edgeIndx<edgeList.size()&&queries[i][2]>edgeList[edgeIndx][2])
            {
                d.Union(edgeList[edgeIndx][0],edgeList[edgeIndx][1]);
                edgeIndx++;
            }
            queryAnswer.push_back({queries[i][3],d.Find(queries[i][0])==d.Find(queries[i][1])});
        }
        sort(queryAnswer.begin(),queryAnswer.end());
        vector<bool>result;
        for(auto x:queryAnswer)
        {
            result.push_back(x.second);
        }
        return result;
    }
};