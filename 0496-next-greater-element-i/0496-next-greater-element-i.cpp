class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>nextg;
        stack<int>st;
        unordered_map<int,int>freq;
        for(int i=nums2.size()-1;i>=0;i--)
        {
            freq[nums2[i]]=i;
            while(!st.empty()&&nums2[st.top()]<=nums2[i])
            {
                st.pop();
            }
            if(st.empty())
                nextg.push_back(-1);
            else 
                nextg.push_back(st.top());
            st.push(i);
        }
        reverse(nextg.begin(),nextg.end());
        vector<int>result;
        for(auto x:nums1)
            result.push_back(nextg[freq[x]]==-1?-1:nums2[nextg[freq[x]]]);
        return result;
    }
};