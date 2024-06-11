class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int>freq(1001,0);
        for(auto &x:arr1)freq[x]++;
        int indx=0;
        for(int i=0;i<arr2.size();i++)
        {
            for(int j=0;j<freq[arr2[i]];j++)
            {
                arr1[indx++]=arr2[i];
            }
            freq[arr2[i]]=0;
        }
        for(int i=0;i<1001;i++)
        {
            for(int j=0;j<freq[i];j++)
            {
                arr1[indx++]=i;
            }
        }
        
        return arr1;
    }
};