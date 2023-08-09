class Solution
{
    vector<int> moveX = { 1,
        1,
        -1,
        -1,
        2,
        2,
        -2,
        -2
    };
    vector<int> moveY = { 2,
        -2,
        2,
        -2,
        1,
        -1,
        1,
        -1
    };
    vector<vector < int>> keypad = {
		{ 1,
            2,
            3 },
        { 4,
            5,
            6 },
        { 7,
            8,
            9 },
        { -1,
            0,
            -1 }
    };
    int mod = 1e9 + 7;
    int dp[4][3][5000];
    
    int helper(int x,int y,int n)
    {
        if(n==0)
            return 1;
        if(dp[x][y][n]!=-1)
            return dp[x][y][n];
        int move=0;
        for(int i=0;i<8;i++)
        {
            int _x=x+moveX[i],_y=y+moveY[i];
            if(_x>=4||_y>=3||_x<0||_y<0||keypad[_x][_y]<0)continue;
            move+=helper(_x,_y,n-1);
            move%=mod;
        }
        return dp[x][y][n]=move;
    }
    
    public:
        int knightDialer(int n)
        {
            int result = 0;
            memset(dp, -1, sizeof(dp));
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (keypad[i][j] >= 0)
                    {
                        result += helper(i, j, n - 1);
                        result %= mod;
                    }
                }
            }
            return result;
        }
};