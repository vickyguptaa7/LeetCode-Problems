class Solution {
public:
    
    bool isPossible(long long time,vector<int>&ranks,int cars)
    {
        for(int i=0;i<ranks.size();i++)
        {
            int canRepairCars=sqrtl((time/ranks[i]));
            cars-=canRepairCars;
            if(cars<=0)
                return true;
        }
        return false;
    }
    
    long long repairCars(vector<int>& ranks, int cars) {
        long long lowTime=1,highTime=1e15,minTime=1;
        while(lowTime<=highTime)
        {
            long long midTime=lowTime+(highTime-lowTime)/2;
            if(isPossible(midTime,ranks,cars))
            {
                minTime=midTime;
                highTime=midTime-1;
            }
            else
            {
                lowTime=midTime+1;
            }
        }
        return minTime;
    }
};