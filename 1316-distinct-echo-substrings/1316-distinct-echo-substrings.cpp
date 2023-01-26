class Solution
{
    public:
    int distinctEchoSubstrings(string text)
    {
        vector<pair<int,int>> substring;
        int n=text.size();
        for (int i = 1; i <= n/ 2; i++)
        {
            int count=0;
            for(int left=0,right=i;left<n-i;left++,right++)
            {
                if(text[left]==text[right])
                {
                    count++;
                }
                else 
                {
                    count=0;
                }
                if(count==i)
                {
                    substring.push_back({left,right-left});
                    count--;
                }
            }
        }
        set<string>ans;
        for(auto [l,r]:substring)
        {
            ans.insert(text.substr(l,r));
        }
        return ans.size();
    }
};