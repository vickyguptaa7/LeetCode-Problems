class Solution {
public:
    int minMaxDifference(int num) {
        string str=to_string(num);
        vector<int>digFreq(10,0);
        bool isFind=false;
        int mxFreq=1;
        char chnge;
        for(int i=0;i<str.size();i++)
        {
            digFreq[str[i]-'0']++;
            if(!isFind&&str[i]!='9'){
                isFind=true;
                chnge=str[i];
            }
            mxFreq=max(mxFreq,digFreq[str[i]-'0']);
        }
        int mx=num;
        if(isFind)
        {
            for(auto &x:str){
                if(chnge==x){
                    x='9';
                }
            }
            mx=stoi(str);
        }
        str=to_string(num);
        chnge=str[0];
        for(auto &x:str){
            if(chnge==x)x='0';
        }
                int mn=stoi(str);
        return mx-mn;
    }
};