class Solution {
public:
    vector<int>init;
    Solution(vector<int>& nums) {
        init=nums;
    }
    
    vector<int> reset() {
        return init;
    }
    
    vector<int> shuffle() {
        vector<int>result=init;
        for(int i=0;i<init.size();i++)
        {
            int indx=rand()%((int)init.size());
            swap(result[i],result[indx]);
        }
        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */