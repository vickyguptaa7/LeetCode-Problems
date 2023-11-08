class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int diffx=abs(sx-fx);
        int diffy=abs(sy-fy);
        if(diffx==0&&diffy==0&&t==1)return false;
        if(max(diffx,diffy)>t)
            return false;
        
        return true;
    }
};