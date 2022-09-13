class Solution {
public:
    bool validUtf8(vector<int>& data) {
        vector<string>bits;
        int skip=0;
        for(int i=0;i<data.size();i++)
        {
            int num=data[i];
            string s;
            int itr=0;
            while(itr++<8)
            {
                s+=to_string(num%2);
                num/=2;
            }
            reverse(s.begin(),s.end());
  
            if(skip)
            {
                skip--;
                if(s[0]=='0'||(s[0]=='1'&&s[1]=='1'))return false;
            }
            else 
            {
                if(s[0]=='0')continue;
                else
                {
                    for(int i=1;i<s.size();i++)
                    {
                        if(s[i]=='0')
                        {
                            break;
                        }
                        else 
                        {
                            skip++;
                        }
                    }
                    if(skip>3||skip==0)return false;
                }
            }
            // cout<<s<<"  "<<skip<<"\n";
        }
        if(skip!=0)return false;
        return true;
    }
};