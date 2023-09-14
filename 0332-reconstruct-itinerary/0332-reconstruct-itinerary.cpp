class Solution {
public:
    
    bool helper(string src,map<string,set<string>>&list,multiset<pair<string,string>>&visit,
               vector<string>&curr,vector<string>&res)
    {
        if(visit.empty())
        {
            res=curr; 
            return true;
        }
        for(auto child:list[src])
        {
            if(!visit.count({src,child}))
                continue;
            auto rem=visit.find({src,child});
            visit.erase(rem);
            curr.push_back(child);
            if(helper(child,list,visit,curr,res))
                return true;
            curr.pop_back();
            visit.insert({src,child});
        }
        return false;
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string>res,curr;
        map<string,set<string>>list;
        multiset<pair<string,string>>visit;
        for(auto ticket:tickets)
        {
            visit.insert({ticket[0],ticket[1]});
            list[ticket[0]].insert(ticket[1]);
        }
        curr.push_back("JFK");
        helper("JFK",list,visit,curr,res);
        return res;
    }
};