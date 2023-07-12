class Solution {
public:
    string convertToTitle(int columnNumber) {
        string converted="";
        while(columnNumber)
        {
            columnNumber--;
            int rem=(columnNumber%26);
            converted=char(rem+'A')+converted;
            columnNumber/=26;
        }
        return converted;
    }
};