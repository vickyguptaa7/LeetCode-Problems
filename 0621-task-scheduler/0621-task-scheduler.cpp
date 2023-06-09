class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n==0)
            return tasks.size();
        vector<int>freq(26,0);
        for(auto ch:tasks)freq[ch-'A']++;
        sort(freq.begin(),freq.end(),greater<int>());
        int cntr=0;
        for(int i=0;i<26;i++)cntr+=(freq[0]==freq[i]);
        return max((freq[0]-1)*(n+1)+cntr,(int)tasks.size());
    }
};