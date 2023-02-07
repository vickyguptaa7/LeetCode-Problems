class Solution {
public:
    
    int maximizeWin(vector<int>& p, int k) {
        int sum=0,n=p.size();
        priority_queue<int>pque;
        map<int,int>freq,score;
        for(int i=n-1;i>=0;i--)
        {
            pque.push(p[i]);
            while(pque.top()-p[i]>k)
            {
                pque.pop();
            }
            freq[i]=pque.size();
            score[pque.size()]++;
        }
        int ansMax=1;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<n-1;i++)
        {
            pq.push(p[i]);
            score[freq[i]]--;
            if(score[freq[i]]==0)
                score.erase(freq[i]);
            while(p[i]-pq.top()>k)
            {
                pq.pop();
            }
            ansMax=max(ansMax,(int)pq.size()+score.rbegin()->first);
        }
        return ansMax;
    }
};