class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int>freq;
        for(auto x:arr)freq[x]++;
        
        vector<int>newArr;
        for(auto x:freq)
            newArr.push_back(x.second);
        
        sort(newArr.begin(),newArr.end(),greater<int>());
        int req=arr.size()/2;
        int cnt=0;
        
        for(int i=0;i<newArr.size();i++)
        {
            req-=newArr[i];
            cnt++;
            if(req<=0)return cnt;
        }
        return cnt;
    }
};