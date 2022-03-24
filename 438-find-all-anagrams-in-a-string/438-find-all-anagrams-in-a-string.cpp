class Solution {
public:
vector<int> findAnagrams(string s, string p)
{
    unordered_map<char,int>fpat;
    for(auto x:p)
    {
        fpat[x]++;
    }
    int counter=fpat.size();
    
    int slen=s.size(),plen=p.size(),right=0,left=0;
    vector<int>result;
    while(right<slen)
    {
        while(right-left<plen)
        {
            if(fpat.find(s[right])!=fpat.end())
            {
                fpat[s[right]]--;
                if(fpat[s[right]]==0)counter--;
            }
            right++;
        }
        if(counter==0)
        {
            result.push_back(left);
        }
        if(fpat.find(s[left])!=fpat.end())
        {
            fpat[s[left]]++;
            if(fpat[s[left]]==1)
            {
                counter++;
            }
        }
        left++;
    }
    return result;
}
};