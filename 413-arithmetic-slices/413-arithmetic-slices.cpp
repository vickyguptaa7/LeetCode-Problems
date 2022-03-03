class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& arr) {
        unordered_map<int,int>umap;
        int count=0,diff=0,n=arr.size();
        for(int i=2;i<n;i++)
        {
            bool isTrue=0;
            if(arr[i-1]-arr[i-2]==arr[i]-arr[i-1])
            {
                                    cout<<arr[i-2]<<","<<arr[i-1]<<","<<arr[i]<<",";
                if(diff==arr[i]-arr[i-1])
                {
                    count++;
                    isTrue=1;
                }
            }
           if(isTrue==0)
            {
                umap[diff]+=((count)*(count+1))/2; 
                if(arr[i-1]-arr[i-2]==arr[i]-arr[i-1])
                {
                    diff=arr[i]-arr[i-1];
                    count=1; 
                }
               else
               {
                   diff=0;
                   count=0;
               }

            }
        }
        umap[diff]+=((count)*(count+1))/2; 
        int answer=0;
        for(auto x:umap)
        {
            answer+=x.second;
        }
        return answer;
    }
};