class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        vector<int>overAllCost(n,0);
        int sumOfCost=0;
        for(int i=0;i<n;i++)
        {
            overAllCost[i]=gas[i]-cost[i];
            sumOfCost+=overAllCost[i];
        }
        if(sumOfCost<0)
            return -1;
        sumOfCost=overAllCost[0];
        int start=0,iter=(1%n);
        while(start!=iter)
        {
            while(sumOfCost<0)
            {
                sumOfCost-=overAllCost[start];
                start=(start+1)%n;
            }
            sumOfCost+=overAllCost[iter];
            iter=(iter+1)%n;
        }
        return start;
    }
};