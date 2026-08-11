class Solution {
    // (y2 - y1) / (x2 - x1) = (y3 - y2) / (x3 - x2)
    public boolean checkStraightLine(int[][] coordinates) {
        if(coordinates.length==2)
            return true;
        int y = coordinates[1][1] - coordinates[0][1];
        int x = coordinates[1][0] - coordinates[0][0];
        for(int i=1;i<coordinates.length;i++)
        {
            int yi = coordinates[i][1] - coordinates[i-1][1];
            int xi = coordinates[i][0] - coordinates[i-1][0];

            if(xi*y != x*yi)
                return false;
        }
        return true;
    }
}