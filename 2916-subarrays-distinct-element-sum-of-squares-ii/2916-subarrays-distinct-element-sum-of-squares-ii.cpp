    int mod=1e9+7;

struct node{
    int first_order;
    int second_order;
    int lazy;
    node(int val=0)
    {
        first_order=val;
        second_order=val*val;
        lazy=0;
    }
};

class SegTree{
    vector<node>tree;
    public:
    SegTree(int size)
    {
        tree.resize(4*size);
        build(1,0,size-1);
    }
    
    node merge(node a,node b)
    {
        node c;
        c.first_order=(a.first_order+b.first_order)%mod;
        c.second_order=(a.second_order+b.second_order)%mod;
        return c;
    }
    
    void build(int id,int l,int r)
    {
        if(l==r)
        {
            return;
        }
        int mid=(l+r)>>1;
        build(id<<1,l,mid);
        build(id<<1|1,mid+1,r);
        tree[id]=merge(tree[id<<1],tree[id<<1|1]);
    }
    
    void push(int id,int l,int r)
    {
        if(tree[id].lazy==0) // no lazy
            return;
        int x=tree[id].lazy;
        // 1^2+2^2 => (1+x)^2 + (2+x)^2 => 1^2 + x^2 + 2*1*x + 2^2 + x^2 + 2*2*x
        // => (1^2 + 2^2) + x^2 + x^2 + 2*x*(1+2)
        // (1^2 + 2^2) => previous second order
        // (1+2) => previous first order
        // formula => second_order + (r-l+1)*x^2 + 2*x*first_order
        tree[id].second_order=(tree[id].second_order + (r-l+1)*1ll*x*x + 2ll*x*tree[id].first_order)%mod;
        tree[id].first_order=(tree[id].first_order+x*(r-l+1ll))%mod;            
        
        tree[id].lazy=0;
        
        if(l==r) // leaf node
            return;
        
        tree[id<<1].lazy+=x;
        tree[id<<1|1].lazy+=x;
    }
    
    void update(int id,int l,int r,int lq,int rq,int x)
    {
        push(id,l,r);
        if(l>rq||r<lq)
        {
            return;
        }
        if(l>=lq&&r<=rq)
        {
            tree[id].lazy=x;
            push(id,l,r);
            return;
        }
        int mid=(l+r)>>1;
        update(id<<1,l,mid,lq,rq,x);
        update(id<<1|1,mid+1,r,lq,rq,x);
        tree[id]=merge(tree[id<<1],tree[id<<1|1]);
    }
    
    node query(int id,int l,int r,int lq,int rq)
    {
        push(id,l,r);
        if(l>rq||r<lq)
        {
            return node();
        }
        if(l>=lq&&r<=rq)
        {
            return tree[id];
        }
        int mid=(l+r)>>1;
        return merge(query(id<<1,l,mid,lq,rq),query(id<<1|1,mid+1,r,lq,rq));
    }
    
    void print()
    {
        cout<<"\nFIRST_ORDER\n";
        for(int i=0;i<tree.size();i++)
        {
            cout<<tree[i].first_order<<" ";
        }
        cout<<"\nSECOND_ORDER\n";
        for(int i=0;i<tree.size();i++)
        {
            cout<<tree[i].second_order<<" ";
        }
        cout<<"\n";
    }
};

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int size=nums.size();
        SegTree tree=SegTree(size);
        unordered_map<int,int>last_seen;
        int ans=0;
        for(int i=0;i<size;i++)
        {
            int prev=-1;
            if(last_seen.count(nums[i]))
            {
                prev=last_seen[nums[i]];
            }
            tree.update(1,0,size-1,prev+1,i,1);
            ans=(ans+tree.query(1,0,size-1,0,i).second_order)%mod;
            last_seen[nums[i]]=i;
        }
        // tree.update(1,0,size-1,0,2,0);
        // node n=tree.query(1,0,size-1,0,0);
        // cout<<n.first_order<<" "<<n.second_order<<"\n";
        return ans;
    }
};