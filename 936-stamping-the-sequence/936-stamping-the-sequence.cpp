class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int>res;
        int m=stamp.size(),n=target.size(),stars=0;
        
        vector<bool>isVisited(n,false);
        
        while(stars<n)
        {
            bool isReplace=false;
            for(int i=0;i<=n-m&&stars<n;i++)
            {
                if(!isVisited[i])
                {
                    isReplace=checkAndReplace(target,i,m,stamp,res,stars);
                    isVisited[i]=isReplace;
                }
            }
            if(!isReplace)return {};
        }
        
        reverse(res.begin(),res.end());
        return res;
    }
    
    bool checkAndReplace(string &target,int strt,int m,string &stamp,vector<int>&ans,int &stars)
    {
        for(int i=0;i<m;i++)
        {
            if(target[i+strt]!='*'&&target[i+strt]!=stamp[i])return false;
        }
        
        ans.push_back(strt);
        
        for(int i=strt;i<strt+m;i++)
        {
            stars+=(target[i]!='*');
            target[i]='*';
        }
        return true;
    }
};