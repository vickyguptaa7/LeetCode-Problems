class Solution {
public:
    string fractionToDecimal(int nume, int deno) {
        if(nume==0)
            return "0";
        string beforeDecimal=to_string(abs((long long)nume/deno));
        long long num=abs((long long)nume);
        long long den=abs((long long)deno);
        bool isNeg=false;
        if(nume<0)
            isNeg=!isNeg;
        if(deno<0)
            isNeg=!isNeg;
        if(num%den==0ll)
            return (isNeg)?"-"+beforeDecimal:beforeDecimal;
        num-=(num/den)*den;
        string afterDecimal="";
        num*=10;
        long long temp=num;
        set<int>oset;
        while(!oset.count(num))
        {
            oset.insert(num);
            while(num<den)
            {
                num*=10;
                afterDecimal+="0";
            }
            afterDecimal+=to_string(num/den);
            num-=(num/den)*den;
            num*=10;
            if(num==0)
                break;
        }
        if(num==0)
        {
            return (isNeg)?"-"+beforeDecimal+"."+afterDecimal
                :beforeDecimal+"."+afterDecimal;
        }
        int iter=0;
        while(temp!=num)
        {
            while(temp<den)
            {
                temp*=10;
                iter++;
            }
            temp-=(temp/den)*den;
            temp*=10;
            iter++;
        }
        afterDecimal.insert(iter,"(");
        return (isNeg)?"-"+beforeDecimal+"."+afterDecimal+")":
        beforeDecimal+"."+afterDecimal+")";
    }
};