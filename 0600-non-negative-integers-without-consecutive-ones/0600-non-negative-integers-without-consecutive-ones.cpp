class Solution {
public:
    
    void helper(int n,int num,int prev,int &cntr)
    {
        if(n>=num*2)
        {
            cntr++;
            helper(n,num*2,0,cntr);
        }
        if(n>=num*2+1&&prev==0)
        {
            cntr++;
            helper(n,num*2+1,1,cntr);
        }
        
    }
    int findIntegers(int n) {
        int cntr=2;// for 0 and 1
        helper(n,1,1,cntr);
        return cntr;
    }
};