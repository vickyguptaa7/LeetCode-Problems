class Solution {
public:
    string reversePrefix(string word, char ch) {
        int indx=word.find(ch);
        if(indx==string::npos)
            return word;
        reverse(word.begin(),word.begin()+indx+1);
        return word;
    }
};