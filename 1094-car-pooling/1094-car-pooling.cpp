class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int>road(1003,0);
        
        int len=trips.size();
        
        for(int i=0;i<len;i++)
        {
            int passenger=trips[i][0];
            int from=trips[i][1];
            int to=trips[i][2];
            road[from+1]+=passenger;
            road[to+1]-=passenger;
        }
        int max_capacity=0;
        for(int i=1;i<1002;i++)
        {
            road[i]+=road[i-1];
            max_capacity=max(max_capacity,road[i]);
            cout<<road[i]<<" ";
        }
        
        return capacity>=max_capacity;
    }
};