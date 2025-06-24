class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int>ele;
        for(int i=0;i<nums.size();i++)
            if(nums[i]==key)
                ele.push_back(i);
        vector<int>res;
        for(int i=0;i<nums.size();i++)
        {
            int mn=INT_MAX;
            int li=lower_bound(ele.begin(),ele.end(),i)-ele.begin();
            if(li-1>=0)
                mn=abs(i-ele[li-1]);
            if(li<ele.size())
                mn=min(mn,abs(i-ele[li]));
            if(li+1<ele.size())
                mn=min(mn,abs(i-ele[li+1]));
            if(k>=mn)
            res.push_back(i);
        }
        return res;
    }
};