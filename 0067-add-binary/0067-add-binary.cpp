class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int it1=(int)a.size()-1,it2=(int)b.size()-1;
        bool carry=false;
        while(it1>=0||it2>=0)
        {
            int sum=0;
            if(it1>=0)sum+=(a[it1]-'0');
            if(it2>=0)sum+=(b[it2]-'0');
            sum+=carry;
            carry=sum/2;
            res+=(sum==3||sum==1)?"1":"0";
            it1--;
            it2--;
        }
        res+=(carry)?"1":"";
        reverse(res.begin(),res.end());
        return res;
    }
};