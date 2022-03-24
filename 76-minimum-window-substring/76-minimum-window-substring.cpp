class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size())return "";
        unordered_map<char,int>freqt;
        for(auto x:t)
        {
            freqt[x]++;
        }
        int cntr=freqt.size();
        int slen=s.size(),tlen=t.size();
        int left=0,right=0;
        int lindx=0,rindx=slen-1;
        bool isFound=0;
        while(slen>right)
        {
            while(slen>right&&cntr!=0)
            {
                if(freqt.find(s[right])!=freqt.end())
                {
                    freqt[s[right]]--;
                    if(freqt[s[right]]==0)cntr--;
                }
                right++;
            }
            
            while(cntr==0)
            {
                if(rindx-lindx>=right-left-1)
                {
                    rindx=right-1;
                    lindx=left;
                    isFound=1;
                }
                if(freqt.find(s[left])!=freqt.end()){
                    freqt[s[left]]++;
                    if(freqt[s[left]]==1)cntr++;
                }
                left++;
      
            }
        }
                
        string res;
        if(isFound==0)return res;
        
        res=s.substr(lindx,rindx-lindx+1);
        return res;
    }
};