class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int peak=max_element(arr.begin(),arr.end())-arr.begin();
        int n=arr.size();
        if(peak==0||peak==n-1)return false;
        int itr=peak;
        while(itr>=1)
        {
            if(arr[itr-1]>=arr[itr])return false;
            itr--;
        }
        itr=peak;
        while(itr<n-1)
        {
            if(arr[itr+1]>=arr[itr])return false;
            itr++;
        }
        return true;
    }
};