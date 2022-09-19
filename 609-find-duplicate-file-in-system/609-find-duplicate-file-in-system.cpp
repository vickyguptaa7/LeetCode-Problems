class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>>result;
        map<string,vector<string>>freq;
        for(int i=0;i<paths.size();i++)
        {
            vector<int>terminate;
            for(int j=0;j<paths[i].size();j++)
                if(paths[i][j]==' ')
                    terminate.push_back(j);
            
            terminate.push_back((int)paths[i].size()-1);
            string dir=paths[i].substr(0,terminate[0]);
            // cout<<dir<<"\n";
            for(int j=1;j<terminate.size();j++)
            {

                int bracket_open=0;
                int bracket_closed=(terminate.size()==j+1)?terminate[j]:terminate[j]-1;
                for(int k=terminate[j-1];k<=terminate[j];k++)
                    if(paths[i][k]=='(')
                    {
                        bracket_open=k;
                        break;
                    }
                
                string file_name=paths[i].substr(terminate[j-1]+1,bracket_open-terminate[j-1]-1);
                string content=paths[i].substr(bracket_open+1,bracket_closed-bracket_open-1);
                // cout<<file_name<<"\n"<<content<<"\n";
                freq[content].push_back(dir+"/"+file_name);
            }
        }
        for(auto x:freq)
        {
            if(x.second.size()>1)
            result.push_back(x.second);
        }
        return result;
    }
};