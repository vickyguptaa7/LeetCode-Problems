class Solution {
public:
    string smallestSubsequence(string s) {
        int arr[26]={0};
        int have[26]={0};
        for(auto ch:s)
            arr[ch-'a']++;
        string ans;
        int pt=0;
        for(auto ch:s)
        {
            if(ans.empty())
            {
                ans+=ch;
                have[ch-'a']++;
            }
            else if(ans.back()>ch) 
            {
                while(!ans.empty()&&have[ch-'a']==0&&arr[ans.back()-'a']!=0&&ans.back()>ch)
                {
                    have[ans.back()-'a']--;
                    ans.pop_back();
                }
                if(have[ch-'a']==0)
                {
                ans+=ch;
                have[ch-'a']++;
                }
            }
            else 
            {
                if(have[ch-'a']==0)
                {
                ans+=ch;
                have[ch-'a']++;
                }
            }
            cout<<ans<<"\n";
            arr[ch-'a']--;
        }
        return ans;
    }
};