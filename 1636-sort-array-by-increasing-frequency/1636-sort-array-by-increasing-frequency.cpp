class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int>freq(202,0);
        for(auto num:nums)freq[num+101]++;
        vector<pair<int,int>>temp;
        for(int i=0;i<freq.size();i++)
        {
            if(freq[i])
                temp.push_back({freq[i],i-101});
        }
        sort(temp.begin(),temp.end(),[](pair<int,int>& a,pair<int,int>& b){
            if(a.first!=b.first)
                return a.first<b.first;
            return a.second>b.second;
        });
        vector<int>res;
        for(auto t:temp)
        {
            for(int i=0;i<t.first;i++)res.push_back(t.second);
        }
        return res;
    }
};