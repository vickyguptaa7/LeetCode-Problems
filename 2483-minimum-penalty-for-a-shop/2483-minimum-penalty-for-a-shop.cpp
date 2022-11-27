class Solution {
public:
    int bestClosingTime(string customers) {
        int time=0,arrTime=0,futTime=0,n=customers.size();
        for(auto x:customers)
        {
            if(x=='Y')
                futTime++;    
        }
        int minPenalty=futTime;
        if(n-futTime<futTime)
        {
            time=n;
        }
        for(int i=0;i<n;i++)
        {
            if(customers[i]=='Y')
                futTime--,arrTime++;
            
            int penalty=i-arrTime+1;
            penalty+=futTime;
            if(minPenalty>penalty||(minPenalty==penalty&&time>i))
            {
                time=i+1;
                minPenalty=penalty;
            }
        }
        cout<<minPenalty<<"\n";
        return time;
    }
};