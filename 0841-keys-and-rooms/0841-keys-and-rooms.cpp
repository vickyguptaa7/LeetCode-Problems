class Solution {
public:
    
    void helper(int src,vector<vector<int>>&rooms,vector<int>&visit)
    {
        visit[src]=true;
        for(auto x:rooms[src])
        {
            if(!visit[x])
            {
                helper(x,rooms,visit);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int>visit(n,false);
        helper(0,rooms,visit);
        for(auto x:visit)
            if(!x)
                return false;
        return true;
    }
};