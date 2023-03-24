class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if(target<=startFuel)
            return 0;
        priority_queue<int>pque;
        int minRefuel=0;
        long long fuelFilled=startFuel;
        for(int i=0;i<stations.size();i++)
        {
            if(fuelFilled>=stations[i][0])
            {
                pque.push(stations[i][1]);
            }
            else
            {
                if(pque.empty())
                {
                    return -1;
                }
                fuelFilled+=pque.top();
                pque.pop();
                minRefuel++;
                i--;
            }
        }
        while(target>fuelFilled)
        {
            if(pque.empty())
                return -1;
            fuelFilled+=pque.top();
            pque.pop();
            minRefuel++;
        }
        return minRefuel;
    }
};