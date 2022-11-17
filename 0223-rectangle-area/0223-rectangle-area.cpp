class Solution
{
    public:
        int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
        {
            int farea = abs(ax1 - ax2) *abs(ay1 - ay2);
            int sarea = abs(bx1 - bx2) *abs(by1 - by2);

            if (ax1 <= bx1 and bx2 <= ax2)
            {
                int len = abs(bx1 - bx2);
                if (ay2 >= by2 and by1 >= ay1)
                {
                    int bred = abs(by2 - by1);
                    return farea + sarea - len * bred;
                }
                else if (ay2 >= by2 and by2 >= ay1 and ay1 >= by1)
                {
                    int bred = abs(by2 - ay1);
                    return farea + sarea - len * bred;
                }
                else if (by2 >= ay2 and ay2 >= by1 and by1 >= ay1)
                {
                    int bred = abs(ay2 - by1);
                    return farea + sarea - len * bred;
                }
                else if (by2 >= ay2 and ay1 >= by1)
                {
                    int bred = abs(ay2 - ay1);
                    return farea + sarea - len * bred;
                }
                else
                {
                    return farea + sarea;
                }
            }
            else if (bx1 <= ax1 and ax1 <= bx2 and bx2 <= ax2)
            {
                int len = abs(ax1 - bx2);
                if (ay2 >= by2 and by1 >= ay1)
                {
                    int bred = abs(by2 - by1);
                    return farea + sarea - len * bred;
                }
                else if (ay2 >= by2 and by2 >= ay1 and ay1 >= by1)
                {
                    int bred = abs(by2 - ay1);
                    return farea + sarea - len * bred;
                }
                else if (by2 >= ay2 and ay2 >= by1 and by1 >= ay1)
                {
                    int bred = abs(ay2 - by1);
                    return farea + sarea - len * bred;
                }
                else if (by2 >= ay2 and ay1 >= by1)
                {
                    int bred = abs(ay2 - ay1);
                    return farea + sarea - len * bred;
                }
                else
                {
                    return farea + sarea;
                }
            }
            else if (ax1 <= bx1 and bx1 <= ax2 and ax2 <= bx2)
            {
                int len = abs(bx1 - ax2);
                if (ay2 >= by2 and by1 >= ay1)
                {
                    int bred = abs(by2 - by1);
                    return farea + sarea - len * bred;
                }
                else if (ay2 >= by2 and by2 >= ay1 and ay1 >= by1)
                {
                    int bred = abs(by2 - ay1);
                    return farea + sarea - len * bred;
                }
                else if (by2 >= ay2 and ay2 >= by1 and by1 >= ay1)
                {
                    int bred = abs(ay2 - by1);
                    return farea + sarea - len * bred;
                }
                else if (by2 >= ay2 and ay1 >= by1)
                {
                    int bred = abs(ay2 - ay1);
                    return farea + sarea - len * bred;
                }
                else
                {
                    return farea + sarea;
                }
            }
            else if (bx1 <= ax1 and ax2 <= bx2)
            {
                int len = abs(ax1 - ax2);
                if (ay2 >= by2 and by1 >= ay1)
                {
                    int bred = abs(by2 - by1);
                    return farea + sarea - len * bred;
                }
                else if (ay2 >= by2 and by2 >= ay1 and ay1 >= by1)
                {
                    int bred = abs(by2 - ay1);
                    return farea + sarea - len * bred;
                }
                else if (by2 >= ay2 and ay2 >= by1 and by1 >= ay1)
                {
                    int bred = abs(ay2 - by1);
                    return farea + sarea - len * bred;
                }
                else if (by2 >= ay2 and ay1 >= by1)
                {
                    int bred = abs(ay2 - ay1);
                    return farea + sarea - len * bred;
                }
                else
                {
                    return farea + sarea;
                }
            }
            else
            {
                return farea + sarea;
            }
        }
};