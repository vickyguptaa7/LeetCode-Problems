class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        if(points.size()<3)
            return 0;
        int count=0;
        for(int i=0;i<points.size();i++)
        {
            map<int,int>freq;
            int x=points[i][0],y=points[i][1];
            for(int j=0;j<points.size();j++)
            {
                if(i==j)
                    continue;
                int _x=points[j][0],_y=points[j][1];
                freq[(x-_x)*(x-_x)+(y-_y)*(y-_y)]++;
            }
            for(auto [n,f]:freq)
            {
                if(f>1)
                {
                    count+=(f)*(f-1);
                }
            }
        }
        return count;
        
    }
};

    