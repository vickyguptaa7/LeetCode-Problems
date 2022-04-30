class Solution {
public:
    vector<double>result;
    map<string,bool>visited;
    map<string,vector<pair<string,double>>>list;
    double queryResult;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        for(int i=0;i<equations.size();i++)
        {
            list[equations[i][0]].push_back({equations[i][1],values[i]});
            list[equations[i][1]].push_back({equations[i][0],1/values[i]});
            visited[equations[i][1]]=false;
            visited[equations[i][0]]=false;
        }
        
        for(int i=0;i<queries.size();i++)
        {
            if(visited.count(queries[i][0])&&visited.count(queries[i][1]))
            {
                queryResult=-1;
                dfs_helper(queries[i][0],queries[i][1],1.0);
                // cout<<queryResult<<"\n";
                result.push_back(queryResult);
            }
            else
            {
                result.push_back(-1);
            }
        }
        return result;
    }
    
    void dfs_helper(string src,string dest,double value)
    {

        if(src==dest)
        {     
            queryResult=value;
            return;
        }
        visited[src]=true;
        for(auto curr:list[src])
        {
            if(visited[curr.first]==false)
            {
                dfs_helper(curr.first,dest,value*curr.second);
            }
        }
        visited[src]=false;
    }
};