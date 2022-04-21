class Solution {
public:
    bool isValid(vector<int>& dist, double hour,int mid)
    {
        double hhour=0;
        for(int i=0;i<dist.size();i++)
        {
            if(i!=(int)dist.size()-1)
            hhour+=ceil(dist[i]/(double)mid);
            else hhour+=dist[i]/(double)mid;
        }
        if(hour<hhour)return false;
        return true;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low=1;
        int high=2e9;
        int answer=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(isValid(dist,hour,mid))
            {
                answer=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return answer;
    }
};