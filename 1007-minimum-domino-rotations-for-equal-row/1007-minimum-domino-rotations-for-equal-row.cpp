class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<int>freq(7,0);
        int n=tops.size();
        for(int i=0;i<n;i++)
        {
            freq[tops[i]]++;
            freq[bottoms[i]]++;
        }
        int candidate=0;
        for(int i=0;i<7;i++)candidate=max(candidate,freq[i]);
        for(int i=0;i<7;i++)if(freq[i]==candidate)candidate=i;
        cout<<candidate<<"\n";
        int ans1=0,ans2=0;
        for(int i=0;i<n;i++)
        {
            if(tops[i]!=candidate&&bottoms[i]!=candidate)
            {
                return -1;
            }
            else
            {
                if(tops[i]!=candidate)ans1++;
                if(bottoms[i]!=candidate)ans2++;
            }
        }
        
        return min(ans1,ans2);
    }
};