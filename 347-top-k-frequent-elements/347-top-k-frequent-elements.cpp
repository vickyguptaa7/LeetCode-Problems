typedef pair<int,int> pp;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>umap;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            umap[nums[i]]++;
        }
        priority_queue<pp,vector<pp>,greater<pp>>pque;
        for(auto x:umap)
        {

            if(pque.size()<k)
            {
                 pque.push({x.second,x.first});
            }
            else if(pque.top().first<x.second)
            {
                pque.pop();
                pque.push({x.second,x.first});
            }     
        }
        vector<int>res;
        while(!pque.empty()){
            res.push_back(pque.top().second);
            pque.pop();
        }
        return res;
    }
};