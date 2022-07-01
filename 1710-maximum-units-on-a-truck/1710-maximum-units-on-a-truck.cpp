class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),[](vector<int>&a,vector<int>&b){
            if(a[1]!=b[1])
                return a[1]>b[1];
            return a[0]>b[0];
        });
        
        int result=0;
        for(auto x:boxTypes)
        {
            if(truckSize>=x[0])
            {
                result+=x[0]*x[1];
                truckSize-=x[0];
            }
            else
            {
                result+=x[1]*truckSize;
                break;
            }
        }
        return result;
    }
};