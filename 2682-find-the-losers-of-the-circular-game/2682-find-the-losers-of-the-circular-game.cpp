class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<int>arr;
        for(int i=0;i<n;i++)arr.push_back(i+1);
        int itr=0,turn=0;
        while(arr[itr]!=-1)
        {
            if(arr[itr]!=-1)
                arr[itr]=-1;
            else break;
            turn++;
            itr=(itr+k*turn)%n;
        }
        vector<int>res;
        for(auto x:arr)
        {
            if(x!=-1)
                res.push_back(x);
        }
        return res;
    }
};