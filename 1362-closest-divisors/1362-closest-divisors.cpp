class Solution {
public:
    vector<int>Closer(int  num)
    {
        int prod=1;
        int strt=sqrt(num);
        cout<<strt<<"\n";
        for(int i=strt;i>1;i--){
            if(num%i==0)
            {
                prod*=i;
                num/=i;
                break;
            }
        }
        if(prod>num)
        {
            return {num,prod};
        }
        else 
        {
            return {prod,num};
        }    
    }
    vector<int> closestDivisors(int num) {
        vector<int>num1=Closer(num+1);
        vector<int>num2=Closer(num+2);
        cout<<num1[0]<<" "<<num1[1]<<"\n";
        cout<<num2[0]<<" "<<num2[1]<<"\n";
        if(abs(num1[1]-num1[0])>abs(num2[1]-num2[0]))return num2;
        else return num1;
    }
};