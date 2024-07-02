class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>freq(1001,0);
        for(auto &x:nums1)freq[x]++;
        vector<int>ans;
        for(auto &x:nums2)
        {
            if(freq[x])
            {
                freq[x]--;
                ans.push_back(x);
            }
        }
        return ans;
    }
};