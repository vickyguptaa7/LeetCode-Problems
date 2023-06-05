class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int diffX=coordinates[1][0]-coordinates[0][0],
            diffY=coordinates[1][1]-coordinates[0][1];
        int commonFac=__gcd(diffX,diffY);
        diffX/=commonFac;
        diffY/=commonFac;
        
        bool isPos=true;
        if(diffX<0)isPos=!isPos;
        if(diffY<0)isPos=!isPos;

        for(int i=2;i<coordinates.size();i++)
        {
            int currDiffX=coordinates[i][0]-coordinates[0][0];
            int currDiffY=coordinates[i][1]-coordinates[0][1];
            bool currIsPos=true;
            
            commonFac=__gcd(currDiffX,currDiffY);
            currDiffX/=commonFac;
            currDiffY/=commonFac;
            
            if(currDiffX<0)currIsPos=!currIsPos;
            if(currDiffY<0)currIsPos=!currIsPos;
            
            if(diffX!=currDiffX||diffY!=currDiffY||isPos!=currIsPos)
            {
                return false;
            }
        }
        return true;
    }
};