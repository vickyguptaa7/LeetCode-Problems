class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>s1,s2;
        for(auto &num:nums1)s1.insert(num);
        for(auto &num:nums2)s2.insert(num);
        
        vector<vector<int>>res;
        vector<int>r1,r2;
        for(auto &num:s1)
        {
            if(!s2.count(num))r1.push_back(num);
        }
        for(auto &num:s2)
        {
            if(!s1.count(num))r2.push_back(num);
        }
        
        res.push_back(r1);
        res.push_back(r2);
        
        return res;
    }
};