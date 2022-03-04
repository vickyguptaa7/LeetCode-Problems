class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>>glasses(101,vector<double>(101));
        glasses[0][0]=poured;
        for(int i=0;i<100;i++)
        {
            for(int j=0;j<=i;j++)
            {
                double excessDrink=max(glasses[i][j]-1,double(0));
                glasses[i][j]-=excessDrink;
                glasses[i+1][j]+=excessDrink/(double)2;
                glasses[i+1][j+1]+=excessDrink/(double)2;
            }
            if(query_row==i)break;
        }
        return glasses[query_row][query_glass];
    }
};