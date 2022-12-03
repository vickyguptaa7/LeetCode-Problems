class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>umap;
        for(auto &x:s)
        {
            umap[x]++;
        }
        priority_queue<pair<int,char>>pque;
        for(auto &x:umap)
        {
            pque.push({x.second,x.first});
        }
        string res;
        while(!pque.empty())
        {
            for(int i=0;i<pque.top().first;i++)
            {
                res+=pque.top().second;
            }
            pque.pop();
        }
        return res;
    }
};