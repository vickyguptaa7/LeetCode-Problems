class Solution {
public:
    double average(vector<int>& salary) {
        int sum=accumulate(salary.begin(),salary.end(),0);
        int mx=*max_element(salary.begin(),salary.end());
        int mn=*min_element(salary.begin(),salary.end());
        return (sum-mx-mn)/(double)(salary.size()-2);
    }
};