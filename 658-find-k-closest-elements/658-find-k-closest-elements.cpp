class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>res;
        int it1=lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        int it2=it1;
        it1--;
        while(it1>=0&&it2<arr.size())
        {
            if(k==0)break;
            if(abs(arr[it1]-x)>abs(arr[it2]-x))
            {
                res.push_back(arr[it2]);
                it2++;
            }
            else
            {
                res.push_back(arr[it1]);
                it1--;
            }
            k--;
        }
        while(k>0&&it1>=0)
        {
            k--;
            res.push_back(arr[it1]);
            it1--;
        }
        while(k>0&&it2<arr.size())
        {
            k--;
            res.push_back(arr[it2]);
            it2++;
        }
        sort(res.begin(),res.end());
        return res;
    }
};