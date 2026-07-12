class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(!arr.size())
            return {};
        vector<int>temp=arr;
        sort(temp.begin(),temp.end());
        map<int,int>mp;
        int rank=1;
        mp[temp.front()]=rank;
        for(int i=1;i<arr.size();i++)
        {
            if(temp[i]>temp[i-1])
            {
                rank++;
            }
            mp[temp[i]]=rank;
        }
        for(int i=0;i<arr.size();i++)
        {
            temp[i]=mp[arr[i]];
        }
        return temp;
    }
};