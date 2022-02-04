class Solution {
public:
    /*

        
        int n=nums.size();
        int zc=0,oc=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)zc++;
            else oc++;
        }
        if(oc==zc)return 2*oc;
        else return 2*min(oc,zc);
    */
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>umap;
        int max_len=0,len=nums.size(),prefix=0;
        
        for(int i=0;i<len;i++)
        {
            prefix+=(nums[i]==0)?-1:1;
            
            if(umap.find(prefix)!=umap.end())
            {
                max_len=max(max_len,i-umap[prefix]);
            }
            else
            {
                umap[prefix]=i;
            }
            
            if(prefix==0)
            {
                max_len=max(max_len,i+1);
            }
        }
        return max_len;
        
    }
};