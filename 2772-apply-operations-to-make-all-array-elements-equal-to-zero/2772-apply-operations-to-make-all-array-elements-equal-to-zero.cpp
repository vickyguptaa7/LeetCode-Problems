class Solution {
public:
bool checkArray(vector<int> &nums, int k)
{
    vector<int> arr(nums.size() + 1, 0);
    map<int,int> st;
    int curr = 0;
    for (int i = 0; i <= nums.size() - k; i++)
    {
        while (!st.empty() && st.begin()->first + k == i)
        {
            curr -= st.begin()->second;
            st.erase(st.begin()->first);
        }
        if (nums[i] != 0)
        {
            if (st.empty())
            {
                st[i]=nums[i];
                curr += nums[i];
                arr[i] += nums[i];
                arr[i + k] -= nums[i];
            }
            else if (curr < nums[i])
            {
                int diff = nums[i] - curr;
                curr += diff;
                arr[i] += diff;
                arr[i + k] -= diff;
                st[i]=diff;
            }
        }
    }
    for (int i = 1; i < nums.size(); i++)
    {
        arr[i] += arr[i - 1];
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (arr[i] != nums[i])
            return false;
    }
    return true;
}
};