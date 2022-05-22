bool mycomp(vector<int>&a1,vector<int>&a2)
{
    return a1[0]<a2[0];
}

class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        int noOfLines=1;
        
        sort(stockPrices.begin(),stockPrices.end(),mycomp);
        
        if(stockPrices.size()==1)return 0;
        
        long double prevSlope=(stockPrices[1][1]-stockPrices[0][1])/(long double)(stockPrices[1][0]-stockPrices[0][0]);
        
        // cout<<stockPrices.size()<<"\n";
        
        for(int i=1;i<stockPrices.size();i++)
        {
            long double currSlope=(stockPrices[i][1]-stockPrices[i-1][1])/(long double)(stockPrices[i][0]-stockPrices[i-1][0]);
            if(prevSlope!=currSlope)
            {
                noOfLines++;
            }
            prevSlope=currSlope;
            cout<<currSlope<<"\n";
        }
        return noOfLines;
    }
};

/*
[[72,98],[62,27],[32,7],[71,4],[25,19],[91,30],[52,73],[10,9],[99,71],[47,22],[19,30],[80,63],[18,15],[48,17],[77,16],[46,27],[66,87],[55,84],[65,38],[30,9],[50,42],[100,60],[75,73],[98,53],[22,80],[41,61],[37,47],[95,8],[51,81],[78,79],[57,95]]
*/