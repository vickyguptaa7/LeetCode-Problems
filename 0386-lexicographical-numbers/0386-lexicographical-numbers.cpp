class Solution {
public:

    void helper(int num,int lvl,int limit,vector<int>&res)
    {
        if(num>limit||(num==0&&lvl!=0))
            return;

        if(num!=0)
            res.push_back(num);

        for(int i=0;i<10;i++)
        {
            helper(num*10+i,lvl+1,limit,res);
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int>res;
        helper(0,0,n,res);
        return res;
    }
};