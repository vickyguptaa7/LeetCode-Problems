class AllOne {
    map<string,int>mp;
    map<int,set<string>>rmp;
public:
    AllOne() {
        
    }
    
    void inc(string key) {
        mp[key]++;
        if(mp[key]!=1)
        {
            rmp[mp[key]-1].erase(key);
            if(rmp[mp[key]-1].size()==0)
                rmp.erase(mp[key]-1);
            
        }
        rmp[mp[key]].insert(key);
    }
    
    void dec(string key) {
        mp[key]--;
        if(mp[key]==0)
        {
            rmp[1].erase(key);
            if(rmp[1].size()==0)
                rmp.erase(1);
            mp.erase(key);            
        }
        else
        {
            rmp[mp[key]+1].erase(key);
            if(rmp[mp[key]+1].size()==0)
                rmp.erase(mp[key]+1);
            rmp[mp[key]].insert(key);
        }
    }
    
    string getMaxKey() {
        if(rmp.empty())
            return "";
        return *(rmp.rbegin()->second.begin());
    }
    
    string getMinKey() {
        if(rmp.empty())
            return "";
        return *(rmp.begin()->second.begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */