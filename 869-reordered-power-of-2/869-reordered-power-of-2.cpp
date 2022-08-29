class Solution {
public:
    bool reorderedPowerOf2(int n) {
        set<string>ans;
        for(int i=0;i<=30;i++)
        {
            string str=to_string((int)pow(2,i));
            sort(str.begin(),str.end());
            ans.insert(str);
        }
        string newNum=to_string(n);
        sort(newNum.begin(),newNum.end());
        if(ans.count(newNum))
        {
            return 1;
        }
        else 
        {
            return 0;
        }
    }
};