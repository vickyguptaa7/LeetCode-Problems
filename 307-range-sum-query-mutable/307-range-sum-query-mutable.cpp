class NumArray {
    vector<int>arr,tree;
public:
    NumArray(vector<int>& nums) {
        int n=nums.size();
        arr=nums;
        tree.resize(4*n,0);
        initialize(0,0,n-1);
    }
    
    int combine(int a,int b)
    {
        return a+b;
    }
    void initialize(int indx,int strt,int end)
    {
        if(strt>end)return;
        
        if(strt==end)
        {
            tree[indx]=arr[strt];
            return;
        }
        int mid=(strt+end)/2;
        initialize(indx*2+1,strt,mid);
        initialize(indx*2+2,mid+1,end);
        tree[indx]=combine(tree[indx*2+1],tree[indx*2+2]);
    }
    
    void update(int indx,int strt,int end,int pos,int val)
    {
        if(strt>pos||end<pos)return;
        if(strt==end)
        {
            tree[indx]=val;
            arr[strt]=val;
            return;
        }
        int mid=(strt+end)/2;
        update(indx*2+1,strt,mid,pos,val);
        update(indx*2+2,mid+1,end,pos,val);
        tree[indx]=combine(tree[indx*2+1],tree[indx*2+2]);
    }
        
    void update(int index, int val) {
        update(0,0,(int)arr.size()-1,index,val);
    }
    
    int sumRange(int indx,int strt,int end,int left,int right)
    {
        if(strt>right||end<left)return 0;
        
        if(strt>=left&&end<=right)
        {
            return tree[indx];
        }
        
        int mid=(strt+end)/2;
        int lleft=sumRange(indx*2+1,strt,mid,left,right);
        int rright=sumRange(indx*2+2,mid+1,end,left,right);
        
        return combine(lleft,rright);
    }
    
    int sumRange(int left, int right) {
        return sumRange(0,0,(int)arr.size()-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */