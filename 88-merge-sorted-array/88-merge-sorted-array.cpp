class Solution
{
    public:
        void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
        {
            vector<int> res;
            int itr1 = 0, itr2 = 0;

            while (itr1 < m && itr2 < n)
            {
                if (nums1[itr1] > nums2[itr2])
                {
                    res.push_back(nums2[itr2]);
                    itr2++;
                }
                else
                {
                    res.push_back(nums1[itr1]);
                    itr1++;
                }
            }

            while (itr1 < m)
            {
                res.push_back(nums1[itr1]);
                itr1++;
            }

            while (itr2 < n)
            {
                res.push_back(nums2[itr2]);
                itr2++;
            }
            
            nums1=res;
        }
};