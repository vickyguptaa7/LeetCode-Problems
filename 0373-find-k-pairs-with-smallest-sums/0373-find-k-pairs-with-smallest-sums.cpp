class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>>kPairs;
        int left=0,right=0;
        k=min((long long)nums1.size()*(long long)nums2.size(),(long long)k);
        priority_queue<pair<int,pair<int,int>> >pque;
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                if(pque.size()==k&&pque.top().first<nums1[i]+nums2[j])
                    break;
                pque.push({nums1[i]+nums2[j],{nums1[i],nums2[j]}});
                if(k<pque.size())
                    pque.pop();
            }
        }
        while(!pque.empty())
        {
            auto curr=pque.top();
            pque.pop();
            kPairs.push_back({curr.second.first,curr.second.second});
        }
        return kPairs;
    }
};