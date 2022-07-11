class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int>crr;
        map<int,int>freq;
        long long sum=0;
        for(int i=0;i<nums1.size();i++)
        {
            crr.push_back(abs(nums1[i]-nums2[i]));
            freq[crr.back()]++;
            sum+=crr.back();
        }
        
        int diff=k1+k2;
        if(diff>=sum)
        {
            return 0;
        }
        
        while(diff>0)
        {
            int num=freq.rbegin()->first;
            int cnt=freq.rbegin()->second;
            freq.erase(num);
            
            if(diff>=cnt)
            {
                diff-=cnt;
                num--;
                if(num!=0)
                 freq[num]+=cnt;
            }
            else 
            {
                freq[num]=cnt-diff;
                num--;
                if(num!=0)
                   freq[num]+=diff;
                diff=0;
            }
        }
        
        long long answer=0;
        for(auto x:freq)
        {
            answer+=x.first*(long long)x.first*x.second;
        }
        return answer;
    }
};