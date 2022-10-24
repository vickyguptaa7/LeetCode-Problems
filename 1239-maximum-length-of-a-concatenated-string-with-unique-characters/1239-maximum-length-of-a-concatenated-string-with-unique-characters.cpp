class Solution {
public:
    int maxLength(vector<string>& arr) {
        int n=arr.size();
        int until=(1<<n),res=0;
        for(int i=0;i<until;i++)
        {
            int num=i,itr=0;
            string s;
            while(num)
            {
                if(num&1)
                    s+=arr[itr];
                itr++;
                num/=2;
            }
            vector<int>cnt(26,0);
            bool isTrue=true;
            for(auto ch:s)
            {
                cnt[ch-'a']++;
                if(cnt[ch-'a']>1)
                {
                    isTrue=false;
                    break;
                }
            }
            if(isTrue)
                res=max(res,(int)s.size());
        }
        return res;
    }
};