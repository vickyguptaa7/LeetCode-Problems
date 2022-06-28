class Solution {
public:
    int minDeletions(string s) {
        vector<int>freq(26,0);
        for(auto x:s)
        {
            freq[x-'a']++;
        }
        vector<int>arr;
        for(auto x:freq)
        {
            if(x!=0)arr.push_back(x);
        }
        sort(arr.begin(),arr.end());
        int del=0;
        set<int>oset;
        for(int i=arr.size()-1;i>=0;i--)
        {
            if(!oset.count(arr[i]))
            {
                oset.insert(arr[i]);
            }
            else 
            {
                int add=arr[i]-*oset.begin()+1;
                if(*oset.begin()==0)
                {
                    del+=arr[i];
                }
                else
                {
                    del+=add;
                    oset.insert(arr[i]-add);
                }

            }
        }
        return del;
    }
};