class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<set<char>>list(words.size());
        // cout<<words.size()<<"\n";
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words[i].size();j++)
            {
                list[i].insert(words[i][j]);
            }
        }
        
        int res=0;
        for(int i=0;i<words.size();i++)
        {
            for(int j=i+1;j<words.size();j++)
            {
                bool isTrue=false;
                for(auto x:list[j])
                {
                    if(list[i].count(x))
                    {
                        isTrue=true;
                        break;
                    }
                }
                if(!isTrue)
                {
                    int temp=words[i].size()*words[j].size();
                    if(res<temp)res=temp;
                }
            }
        }
        return res;
    }
};