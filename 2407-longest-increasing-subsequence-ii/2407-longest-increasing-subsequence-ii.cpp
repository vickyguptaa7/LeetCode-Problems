typedef long long ll;
struct node
{
    ll val;
    ll cnt;
    // can add more if required or remove
    node(ll v = 0, ll c = 0)
    {
        val = v;
        cnt = c;
    }
};

class segTree
{
public:
    vector<node> segArr;
    vector<int> narr;

    segTree(int size)
    {
        int arrSize = size;
        narr.resize(size+1,0);
        /*
 we are constructing tree in form of array linearly therefore
we have to make 4*n size array for n size given array
*/
        segArr.resize(4 * arrSize);
        constructSegTree(0, 0, arrSize - 1);
    }

    // here you can change the combine logic according to questions
    node Combine(node &left, node &right)
    {
        return node(max(left.val,right.val), 0);
    }

    void constructSegTree(int index, int startIndx, int endIndx)
    {
        if (startIndx == endIndx)
        {
            // Leaf Logic
            segArr[index] = node(narr[startIndx], 0);
            return;
        }
        int midIndx = startIndx + (endIndx - startIndx) / 2;

        constructSegTree(2 * index + 1, startIndx, midIndx);
        constructSegTree(2 * index + 2, midIndx + 1, endIndx);
        segArr[index] = Combine(segArr[2 * index + 1], segArr[2 * index + 2]);
    }
    node getQuery(int index, int startIndx, int endIndx, int lquery, int rquery)
    {
        // no overlap
        if (startIndx > rquery || lquery > endIndx)
            return node(0, 0);

        // complete overlap
        if (startIndx >= lquery && endIndx <= rquery)
            return segArr[index];

        // partial overlap
        int midIndx = startIndx + (endIndx - startIndx) / 2;
        node left = getQuery(index * 2 + 1, startIndx, midIndx, lquery, rquery);
        node right = getQuery(index * 2 + 2, midIndx + 1, endIndx, lquery, rquery);

        return Combine(left, right);
    }

    void updateQuery(int index, int startIndx, int endIndx, int position, int val)
    {
        if (position < startIndx || position > endIndx)
            return;

        if (startIndx == endIndx)
        {
            // Leaf Condition
            segArr[index] = node(val, 0);
            narr[startIndx] = val;
            return;
        }

        int midIndx = startIndx + (endIndx - startIndx) / 2;
        updateQuery(2 * index + 1, startIndx, midIndx, position, val);
        updateQuery(2 * index + 2, midIndx + 1, endIndx, position, val);
        segArr[index] = Combine(segArr[2 * index + 1], segArr[2 * index + 2]);
    }

    // Use To Get The result of the queries
    void updateQuery(int postion, int value)
    {
        updateQuery(0, 0, (int)narr.size() - 1, postion, value);
    }

    node getQuery(int lquery, int rquery)
    {
        return getQuery(0, 0, (int)narr.size() - 1, lquery, rquery);
    }
};
// use 0 based indexing while calling the update and query func 


class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        int Max=*max_element(nums.begin(),nums.end());
        segTree tree(Max);
        int n=nums.size(),res=0;
        for(int i=0;i<n;i++)
        {
            int left=max(nums[i]-k,1),right=nums[i]-1;
            int query=tree.getQuery(left,right).val;
            res=max(res,query+1);
            tree.updateQuery(nums[i],query+1);
        }
        return res;
    }
};
/*

*/