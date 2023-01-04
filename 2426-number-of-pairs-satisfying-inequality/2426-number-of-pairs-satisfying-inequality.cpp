/* _______________Policy Based DS______________*/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update >;
// provides find_by_order, order_of_key
/*_____________________________________________*/

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int size=nums1.size();
        vector<int>combineNums(size);
        for(int i=0;i<size;i++)
        {
            combineNums[i]=nums1[i]-nums2[i];
        }
        ordered_set<int>oset;
        long long ans=0;
        for(int i=0;i<size;i++)
        {
            long long posible=oset.order_of_key(combineNums[i]+diff+1);
            ans+=posible;
            oset.insert(combineNums[i]);
        }
        return ans;
    }
};