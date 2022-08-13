class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int cnt=words.size();
        map<string,int>freq,temp;
        for(auto x:words)freq[x]++;
        
        vector<int>res;
        int n=s.size(),w=words[0].size(),strt=0;
        
        for(int i=0;i<=n-(int)w*cnt;i++)
        {
            temp=freq;
            bool isTrue=true;
            for(int j=0;j<cnt;j++)
            {
                string srr=s.substr(i+j*w,w);
                if(temp.count(srr))
                {
                    if(temp[srr]==0)
                    {
                        isTrue=false;
                        break;
                    }
                    else
                    {
                        temp[srr]--;
                    }
                }
                else
                {
                    isTrue=false;
                    break;
                }
            }
            if(isTrue)res.push_back(i);
        }
        return res;
    }
};