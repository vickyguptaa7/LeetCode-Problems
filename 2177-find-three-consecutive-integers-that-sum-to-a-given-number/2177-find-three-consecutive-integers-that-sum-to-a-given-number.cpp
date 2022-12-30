class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        if(num%3!=0)
            return {};
        long long num1=(num/3)-1;
        long long num2=(num/3);
        long long num3=(num/3)+1;
        if(num1+num2+num3==num)
            return {num1,num2,num3};
        return {};
    }
};