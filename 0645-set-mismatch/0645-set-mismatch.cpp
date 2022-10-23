class Solution {
public:
    vector<int> findErrorNums(vector<int>& arr) {
        vector<int>res;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[abs(arr[i])-1]<0)
            {
                res.push_back(abs(arr[i]));
            }
            else
            {
                arr[abs(arr[i])-1]=-arr[abs(arr[i])-1];
            }
        }
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]>0)
            {
                res.push_back(i+1);
                break;
            }
        }
        return res;
    }
};