class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int cntr=0,iter=0;
        for(int i=1;i<=2500;i++)
        {
            if(iter<arr.size()&&i==arr[iter])
            {
                iter++;
                continue;
            }
            cntr++;
            if(cntr==k)
                return i;
        }
        return -1;
    }
};