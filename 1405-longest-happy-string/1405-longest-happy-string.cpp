class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        multiset<pair<int,char>>freq;
        if(a)
            freq.insert({a,'a'});
        if(b)
            freq.insert({b,'b'});
        if(c)
            freq.insert({c,'c'});
        string res;
        while(freq.size()>1)
        {
            auto tp=freq.begin();
            pair<int,char>top={tp->first,tp->second};
            freq.erase(tp);
            auto bt=freq.end();
            bt=prev(bt);
            pair<int,char>bottom={bt->first,bt->second};
            freq.erase(bt);
            if(!res.empty()&&res.back()==bottom.second)
            {
                res+=bottom.second;
                res+=top.second;
                if(bottom.first-1>0)
                    freq.insert({bottom.first-1,bottom.second});
                
                if(top.first-1>0)
                    freq.insert({top.first-1,top.second});        
            }
            else
            {
                for(int i=0;i<min(2,bottom.first);i++)res+=bottom.second;
                    res+=top.second;
            
                if(bottom.first-min(2,bottom.first)>0)
                    freq.insert({bottom.first-min(2,bottom.first),bottom.second});
                
                if(top.first-1>0)
                    freq.insert({top.first-1,top.second});
            }
                
        }
        if(!freq.empty())
        {
            auto tp=freq.begin();
            pair<int,char>top={tp->first,tp->second};
            freq.erase(tp);
            for(int i=0;i<min(2,top.first);i++)res+=top.second;
            return res;
        }
        else
        {
            return res;
        }
    }
};