class Solution {
public:
    long double isValid(long double mid, vector<vector<int>>&squares)
    {
        long double above=0,below=0;
        for(auto& square:squares)
        {
            if(mid>=square[1]&& mid <= square[1]+square[2])
            {
                below += (mid-square[1])*(double)square[2];
                above += (square[1]+square[2]-mid)*(double)square[2];
            }
            else if(mid>square[1])
            {
                below += square[2]*(double)square[2];
            }
            else
            {
                above += square[2]*1ll*square[2];
            }
        }
        return above;
    }

    double separateSquares(vector<vector<int>>& squares) {
        long double mn=0,mx=2e9, diff = 0.000001,halfArea = isValid(0,squares)/2.0;
        while(abs(mx-mn)>diff)
        {
            long double mid=(mx+mn)/(double)2.0;
            if(isValid(mid,squares)<=halfArea)
            {
                mx=mid;
            }
            else 
            {
                mn = mid;
            }
        }
        return mx;
    }
};