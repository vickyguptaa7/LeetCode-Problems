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
    vector<ll> narr;

    segTree(vector<pair<int,int>> arr)
    {
        int arrSize = arr.size();
        for(auto x:arr)narr.push_back(x.first+x.second);
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
        return node(max(left.val , right.val), 0);
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


bool mycomp(pair<int,int>&a,pair<int,int>&b)
{
    return( a.first<b.first)||(a.first==b.first&&a.second<b.second);
}

class Solution {
public:
    
    int findLeft(vector<pair<int,int>>&arr,int val)
    {
        int n=arr.size();
        int l=0,h=n-1,indx=0;
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(arr[mid].first>=val)
            {
                indx=mid;
                h=mid-1;
            }
            else 
            {
                l=mid+1;
            }
        }
        return indx;
    }
    
    int findRight(vector<pair<int,int>>&arr,int val)
    {
        int n=arr.size();
        int l=0,h=n-1,indx=0;
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(arr[mid].second>=val)
            {
                indx=mid;
                l=mid+1;
            }
            else 
            {
                h=mid-1;
            }
        }
        return indx;
    }
    
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        vector<pair<int,int>>arr;
        for(int i=0;i<nums1.size();i++)
            arr.push_back({nums1[i],nums2[i]});
        sort(arr.begin(),arr.end(),mycomp);
        vector<pair<int,int>>narr={arr[0]};
        for(int i=1;i<arr.size();i++)
        {
            while(!narr.empty()&&narr.back().first<=arr[i].first&&narr.back().second<=arr[i].second)
            {
                narr.pop_back();
            }
            narr.push_back(arr[i]);
        }
        // for(auto x:narr)cout<<x.first<<" "<<x.second<<"\n";
        // cout<<"\n";
        segTree tree(narr);
        vector<int>result;
        for(int i=0;i<queries.size();i++)
        {
            int indx1=findLeft(narr,queries[i][0]),indx2=findRight(narr,queries[i][1]);
            if(narr[indx1].first<queries[i][0]||narr[indx2].second<queries[i][1]||indx1>indx2)
            {
                result.push_back(-1);
                continue;
            }
            result.push_back(tree.getQuery(indx1,indx2).val);
        }
        return result;
    }
};