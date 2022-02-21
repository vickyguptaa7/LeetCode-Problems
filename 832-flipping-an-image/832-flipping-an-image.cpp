class Solution {
public:

    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int row=image.size(),col=image[0].size();
        for(int i=0;i<row;i++)
        {
            reverse(image[i].begin(),image[i].end());
            for(auto &x:image[i])
            {
                if(x==0)
                    x=1;
                else
                    x=0;
            }
        }
        return image;
    }
};