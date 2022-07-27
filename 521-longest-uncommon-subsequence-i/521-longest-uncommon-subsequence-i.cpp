class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a==b)return -1;
        else return max(b.size(),a.size());
    }
};