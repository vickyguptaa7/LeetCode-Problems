class Allocator {
public:
    map<int,vector<pair<int,int>>>mmid;
    vector<bool>isAlloc;
    int n;
    Allocator(int n) {
        this->n=n;
        isAlloc.resize(n,0);
    }
    
    int allocate(int size, int mID) {
        int sindx=-1;
        for(int i=0;i<n;i++)
        {
            if(isAlloc[i]==0)
            {
                if(n-i<size)
                    return -1;
                bool isFind=true;
                for(int j=i;j<i+size;j++)
                {
                    if(isAlloc[j]==1)
                    {
                        i=j;
                        isFind=false;
                        break;
                    }
                }
                if(isFind)
                {
                    sindx=i;
                    break;
                }
            }
        }
        if(sindx==-1)
            return -1;
        for(int i=sindx;i<sindx+size;i++)
            isAlloc[i]=true;
        mmid[mID].push_back({sindx,size});
        return sindx;
    }
    
    int free(int mID) {
        int memFree=0;
        for(auto x:mmid[mID])
        {
            memFree+=x.second;
            for(int i=x.first;i<x.first+x.second;i++)
            {
                isAlloc[i]=false;
            }
        }
        mmid.erase(mID);
        return memFree;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */