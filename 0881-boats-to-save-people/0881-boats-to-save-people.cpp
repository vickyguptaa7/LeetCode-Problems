class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int boats=0,n=people.size();
        sort(people.begin(),people.end());
        int left=0,right=n-1;
        while(left<=right)
        {
            if(people[left]+people[right]<=limit)
            {
                left++;
            }
            right--;
            boats++;
        }
        return boats;
    }
};