class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int boatreq=0;
        int low=0,high=people.size()-1;
        while(low<=high)
        {
            int total=people[low]+people[high];
            if(total<=limit)
            {
                low++;
                high--;
            }
            else 
            {
                high--;
            }
            boatreq++;
        }
        return boatreq;
    }
};