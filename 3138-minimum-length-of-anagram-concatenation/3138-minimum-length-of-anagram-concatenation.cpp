class Solution {
public:
    
    bool helper(int k,string &s)
    {
        int n=s.size();
        vector<int>freq(26,0);
        for(int i=0;i<k;i++)
        {
            freq[s[i]-'a']++;
        }
        for(int i=k;i<n;i+=k)
        {
            vector<int>temp(26,0);
            for(int j=i;j<i+k;j++)
            {
                temp[s[j]-'a']++;
            }
            if(temp!=freq)
                return false;
        }
        return true;
    }
    
    int minAnagramLength(string s) {
        int n=s.size();
        int res=1e9;
        for(long long i=1;i*i<=n;i++)
        {
            if(n%i==0)
            {
                if(helper(i,s))
                {
                    res=min((int)i,res);
                }
                if(helper(n/i,s))
                {
                    res=min(n/(int)i,res);
                }
            }
        }
        return res;
    }
};