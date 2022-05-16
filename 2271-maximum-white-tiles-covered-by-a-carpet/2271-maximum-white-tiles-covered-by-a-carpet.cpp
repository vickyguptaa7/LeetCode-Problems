class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(),tiles.end());
        int prev=0,cover=0,maxCover=0;
        for(int i=0;i<tiles.size()&&maxCover<carpetLen;i++)
        {
            if(prev==i||tiles[i][1]-tiles[prev][0]<carpetLen)
            {
                cover+=min(carpetLen,tiles[i][1]-tiles[i][0]+1);
                maxCover=max(maxCover,cover);
            } 
            else
            {
                int partials=max(0,tiles[prev][0]+carpetLen-tiles[i][0]);
                maxCover=max(maxCover,cover+partials);
                cover-=tiles[prev][1]-tiles[prev][0]+1;
                prev++;
                i--;
            }
        }
        return maxCover;
    }
};