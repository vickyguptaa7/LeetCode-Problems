class Solution {
public:
    int largestVariance(string s) {
        int n=s.size();
        int result=0;
        map<char,pair<int,int>>freq;
        
        for(int i=0;i<n;i++)
        {
            freq[s[i]]={freq[s[i]].first+1,i};
        }
     
        if(freq.size()==1||freq.size()==n)return 0;
        
        for(int i=0;i<26;i++)
        {
            for(int j=0;j<26;j++)
            {
                char a='a'+i,b=j+'a';
                if(i==j||freq.count(a)==0||freq.count(b)==0)continue;
                
                int fc=0,sc=0;
                for(int k=0;k<n;k++)
                {
                    if(s[k]==a)fc++;
                    else if(s[k]==b) sc++;
                    
                    if(fc>0)result=max(result,sc-fc);
                    
                    if(fc>sc&&freq[a].second>k)
                    {
                        fc=0;
                        sc=0;
                    }
                }
            }
        }
        return result;
    }
};