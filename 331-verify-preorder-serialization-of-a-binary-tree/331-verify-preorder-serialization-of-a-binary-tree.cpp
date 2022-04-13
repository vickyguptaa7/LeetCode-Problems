class Solution {
public:
    bool isValidSerialization(string preorder) {
        stringstream ss(preorder);
        int nodesCount=1;
        string temp;
        while(getline(ss,temp,','))
        {
            nodesCount--;
            if(nodesCount<0)return false;
            if(temp!="#")nodesCount+=2;
        }
        return nodesCount==0;
    }
};