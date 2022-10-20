class Solution {
public:
    string intToRoman(int num) {
        vector<int>arr={1,4,5,9,10,40,50,90,100,400,500,900,1000};
        vector<string>srr={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        string res;
        while(num)
        {
            int indx=upper_bound(arr.begin(),arr.end(),num)-arr.begin();
            indx--;
            res+=srr[indx];
            num-=arr[indx];
        }
        return res;
    }
};