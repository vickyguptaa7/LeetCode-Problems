class Solution {
public:
    int findClosest(int x, int y, int z) {
        return abs(x-z)==abs(y-z)?0:abs(x-z)>abs(y-z)?2:1;
    }
};