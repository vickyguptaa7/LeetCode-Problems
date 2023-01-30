class Solution {
public:
    double x_cor,y_cor,rad;
    Solution(double radius, double x_center, double y_center) {
        x_cor=x_center;
        y_cor=y_center;
        rad=radius;
        srand(time(NULL));
    }
    double getRandom()
    {
        return ((double)rand()/RAND_MAX);
    }
    vector<double> randPoint() {
        // uniformy distribute the points on the circle  
        double len=sqrt(getRandom())*rad;
        double deg=2*M_PI*getRandom();
        return {x_cor+len*cos(deg),y_cor+len*sin(deg)};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */