class Compare {
    public:
       bool operator()(pair<int,int> a, pair<int,int> b){
           long double first=a.first/(long double)a.second;
           long double second=b.first/(long double)b.second;
           return first<second;
      }
};

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,Compare>pque;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            for(int j=n-1;j>i;j--)
            {
                pque.push({arr[i],arr[j]});
                if(pque.size()>k)
                {
                    auto curr=pque.top();
                    pque.pop();
                    if(curr.first==arr[i]&&curr.second==arr[j])
                        break;
                }
            }
        }
        return {pque.top().first,pque.top().second};
    }
};