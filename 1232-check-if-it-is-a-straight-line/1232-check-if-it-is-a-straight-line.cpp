class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int diffX=coordinates[1][0]-coordinates[0][0],
            diffY=coordinates[1][1]-coordinates[0][1];
        
        for(int i=2;i<coordinates.size();i++)
        {
            int currDiffX=coordinates[i][0]-coordinates[0][0];
            int currDiffY=coordinates[i][1]-coordinates[0][1];
            
            if(currDiffY*diffX!=currDiffX*diffY)
            {
                return false;
            }
        }
        return true;
    }
};