class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        map<int,int>mmp;
        for(int i=0;i<n;i++)
        {
            mmp[score[i]]=i;
        }
        vector<string>res(n);
        int rank=1;
        for(auto it=mmp.rbegin();it!=mmp.rend();it++)
        {
            if(rank==1)
            {
                res[it->second]="Gold Medal";
            }
            else if(rank==2)
            {
                res[it->second]="Silver Medal";
            }
            else if(rank==3)
            {
                res[it->second]="Bronze Medal";
            }
            else
            {
                res[it->second]=to_string(rank);
            }
            rank++;
        }
        return res;
    }
};