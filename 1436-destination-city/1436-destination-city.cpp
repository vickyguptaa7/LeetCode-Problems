class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string,int>freq;
        for(auto path:paths)
        {
            freq[path[0]]++;
        }
        for(auto path:paths)
        {
            if(!freq.count(path[0]))
                return path[0];
            if(!freq.count(path[1]))
                return path[1];       
        }
        return "";
    }
};