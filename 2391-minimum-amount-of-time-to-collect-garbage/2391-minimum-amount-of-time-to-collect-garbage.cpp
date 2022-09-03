class Solution {
public:

    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int cost=0;
        vector<int>tcost={0,0,0};
        for(int i=0;i<garbage.size();i++)
        {
            int mc=0,pc=0,gc=0;
            if(i!=0)
            {
                tcost[0]+=travel[i-1];
                tcost[1]+=travel[i-1];
                tcost[2]+=travel[i-1];
            }
            for(auto x:garbage[i])
            {
                if(x=='M')mc++;
                else if(x=='G')gc++;
                else pc++;
            }
            if(mc!=0)
            {
                cost+=tcost[0]+mc;
                tcost[0]=0;
            }
            if(pc!=0)
            {
                cost+=tcost[1]+pc;
                tcost[1]=0;
            }
            if(gc!=0)
            {
                cost+=tcost[2]+gc;
                tcost[2]=0;
            }
        }
        return cost;
    }
};