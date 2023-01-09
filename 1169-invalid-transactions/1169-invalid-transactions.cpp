class Solution {
public:
    vector<string> invalidTransactions(vector<string>& trans) {
        vector<vector<string>>trans2d;
        set<int>invalidIndx;
        for(int i=0;i<trans.size();i++)
        {
            vector<string>iTrans;
            string word;
            for(int j=0;j<trans[i].size();j++)
            {
                if(trans[i][j]==',')
                {
                    // cout<<word<<" ";
                    iTrans.push_back(word);
                    word="";
                }
                else
                    word+=trans[i][j];
            }
            // cout<<word<<"\n";
            iTrans.push_back(word);
            trans2d.push_back(iTrans);
        }
        for(int i=0;i<trans.size();i++)
        {
            if(stoi(trans2d[i][2])>1000)
                invalidIndx.insert(i);
            for(int j=i+1;j<trans.size();j++)
            {
                if(stoi(trans2d[j][2])>1000)
                    invalidIndx.insert(j);
                if(trans2d[i][0]==trans2d[j][0]&&
                  trans2d[i][3]!=trans2d[j][3])
                {
                    int t1=stoi(trans2d[i][1]),t2=stoi(trans2d[j][1]);
                    if(abs(t1-t2)<=60)
                    {
                        invalidIndx.insert(i);
                        invalidIndx.insert(j);
                    }
                }
                    
            }
        }
        vector<string>result;
        for(auto x:invalidIndx)
        {
            result.push_back(trans[x]);
        }
        return result;
    }
};