bool mycomp(string s1,string s2)
{
    return s1.size()<s2.size();
}
class Solution {
public:
    
    int dfs(int src,vector<int>list[],vector<int>&distance)
    {
        if(distance[src]!=-1)return distance[src];
        
        int maxDis=0;
        for(auto x:list[src])
        {
            maxDis=max(maxDis,dfs(x,list,distance));
        }
        distance[src]=maxDis;
        return maxDis+1;
    }
    
    bool Check(string s1,string s2)
    {
        bool isSkip=false;
        for(int i=0;i<s2.size();i++)
        {
            if(s1[i+isSkip]!=s2[i])
            {
                if(isSkip)return false;
                isSkip=true;
                if(s1[i+isSkip]!=s2[i])return false;
            }
        }
        return true;
    }
    
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),mycomp);

        vector<int>list[n];
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int s1=words[i].size(),s2=words[j].size();
                if(s1==s2)
                {
                    continue;
                }
                else if(s2-s1>1)
                {
                    break;
                }
                else
                {
                    if(Check(words[j],words[i]))
                    {
                        list[i].push_back(j);
                    }
                }
            }
        }
        vector<int>distance(n,-1);
        for(int i=0;i<n;i++)
        {
            dfs(i,list,distance);
        }
        return *max_element(distance.begin(),distance.end())+1;
    }
};