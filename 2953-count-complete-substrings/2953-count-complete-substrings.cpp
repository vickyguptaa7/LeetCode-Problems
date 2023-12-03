class Solution {
public:
    
    int helper(string &word,int size,int k)
    {
        if(size>word.size())
            return 0;
        int prev=0,curr=0;
        vector<int>freq(26,0);
        int res=0,kequal=0;
        // cout<<size<<" "<<k<<"\n";
        while(curr<word.size())
        {
            freq[word[curr++]-'a']++;
            
            if(freq[word[curr-1]-'a']==k)
                kequal++;
            
            if(curr>1&&abs(word[curr-1]-word[curr-2])>2)
            {
                while(prev<curr-1)
                {
                    if(freq[word[prev]-'a']==k)
                        kequal--;
                    freq[word[prev++]-'a']--;
                }
            }
            while(freq[word[curr-1]-'a']>k)
            {
                if(freq[word[prev]-'a']==k)
                        kequal--;
                freq[word[prev++]-'a']--;   
            }
            // cout<<kequal<<" ";
            if(size==curr-prev)
            {
                res+=kequal==(size/k);
                if(freq[word[prev]-'a']==k)
                        kequal--;
                freq[word[prev++]-'a']--; 
            }
        }
        // cout<<"\n\n";
        return res;
    }
    
    int countCompleteSubstrings(string word, int k) {
        int res=0;
        for(int i=1;i<=26;i++)
        {
            res+=helper(word,k*i,k);
        }
        return res;
    }
};