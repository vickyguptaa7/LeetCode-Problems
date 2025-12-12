class Solution {
public:

    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int>mentions(numberOfUsers);
        int increment_all=0;
        map<int,vector<int>>offline;
        set<int>users_offline;
        sort(events.begin(),events.end(),[](vector<string>&a,vector<string>&b){
            if(a[1]!=b[1])
                return stoi(a[1])<stoi(b[1]);
            return 
                a[0]>b[0];
        });
        for(auto event:events)
        {
            while(!offline.empty()&&offline.begin()->first<=stoi(event[1]))
            {
                for(auto x:offline.begin()->second)
                    users_offline.erase(x);
                offline.erase(offline.begin()->first);
            }
            if(event[0]=="OFFLINE")
            {
                offline[stoi(event[1])+60].push_back(stoi(event[2]));
                users_offline.insert(stoi(event[2]));
            }
            else
            {
                if(event[2]=="ALL"||event[2]=="HERE")
                {
                    for(int i=0;i<numberOfUsers;i++)
                    {
                        if(users_offline.count(i)&&event[2]=="HERE")continue;
                        mentions[i]++;
                    }
                }
                else
                {
                    for(int i=0;i<event[2].size();i++)
                    {
                        if(event[2][i]=='d')
                        {
                            string num;
                            while(event[2].size()>i+1&&event[2][i+1]>='0'&&event[2][i+1]<='9')
                            {
                                num+=event[2][i+1];
                                i++;
                            }
                            mentions[stoi(num)]++;
                        }
                    }
                }
            }
        }
        return mentions;
    }
};