class Solution {
public:
    
    string decToBinary(int n)
    {
        string bin="";
        while(n)
        {
            bin+=(n&1)?"1":"0";
            n/=2;
        }
        return bin;
    }
    
    long long minEnd(int n, int x) {
        n--;
        string num=decToBinary(x),num2=decToBinary(n);
        while(num.size()<63)
        {
            num+="0";
        }
        int curr=0;
        long long ans=0;
        for(int i=0;i<num2.size();i++)
        {
            while(num[curr]=='1')
            {
                curr++;
            }
            num[curr]=num2[i];
            curr++;
        }
        
        for(int i=0;i<num.size();i++)
        {
            if(num[i]=='0')continue;
            ans|=(1ll<<i);
        }
        return ans;
    }
};