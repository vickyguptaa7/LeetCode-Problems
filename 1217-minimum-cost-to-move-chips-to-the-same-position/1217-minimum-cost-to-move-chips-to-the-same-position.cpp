class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int odd_c=0;
        for(auto &x:position)
        {
            if(x&1)
            {
                odd_c++;
            }
        }
        int even_c=position.size()-odd_c;
        return odd_c>even_c?even_c:odd_c;
    }
};