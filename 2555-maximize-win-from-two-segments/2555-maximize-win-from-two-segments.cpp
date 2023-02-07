class Solution {
public:
    
    int maximizeWin(vector<int>& p, int k) {
        int sum=0,n=p.size();
        int prev=n-1;
        map<int,int>freq,score;
        for(int i=n-1;i>=0;i--)
        {
            while(p[prev]-p[i]>k)
            {
                prev--;
            }
            freq[i]=prev-i+1;
            score[prev-i+1]++;
        }
        int ansMax=1;
        prev=0;
        for(int i=0;i<n-1;i++)
        {
            score[freq[i]]--;
            if(score[freq[i]]==0)
                score.erase(freq[i]);
            while(p[i]-p[prev]>k)
            {
                prev++;
            }
            ansMax=max(ansMax,i-prev+1+score.rbegin()->first);
        }
        return ansMax;
    }
};