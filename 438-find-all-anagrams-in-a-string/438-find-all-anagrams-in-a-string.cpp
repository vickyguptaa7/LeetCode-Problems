class Solution {
public:
vector<int> findAnagrams(string s, string p)
{
    vector<int>fp(26,0),fs(26,0);
    vector<int>result;
    int len1=s.length(),len2=p.length();
    for(auto x:p)
    {
        fp[x-'a']++;
    }
    
    int left=0,right=0;
    while(right<len1)
    {
        if(len2>right-left)
        {
            fs[s[right]-'a']++;
            right++;
        }
        else
        {
            if(fs==fp)
            {
                result.push_back(left);
            }
            fs[s[left]-'a']--;
            left++;
        }
    }
    if(fs==fp)
    {
        result.push_back(left);
    }
    return result;
}
};