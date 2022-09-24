class Solution {
public:
vector<int> smallestSubarrays(vector<int> &nums)
{
    vector<int> bits(31, 0), dbits(31, 0), result;
    for (int i = 0; i < nums.size(); i++)
    {
        int num = nums[i], it = 0;
        while (num)
        {
            if (num & 1)
                bits[it]++;
            num /= 2;
            it++;
        }
    }
    int next = -1, curr = 0;
    while (curr < nums.size())
    {

        int cand = 0;
        for (int i = 0; i < 31; i++)
        {
            if (bits[i])
                cand += (1ll << i);
        }
        int num = 0;
        for (int j = 0; j < 31; j++)
        {
            if (dbits[j])
                num += (1ll << j);
        }
        if (num != cand)
            for (int i = next + 1; i < nums.size(); i++)
            {
                num = nums[i];
                int it = 0;
                while (num)
                {
                    if (num & 1)
                        dbits[it]++;
                    num /= 2;
                    it++;
                }
                num = 0;
                for (int j = 0; j < 31; j++)
                {
                    if (dbits[j])
                        num += (1ll << j);
                }
                next = i;
                if (num == cand)
                {
                    break;
                }
            }
        int temp = nums[curr], it = 0;
        while (temp)
        {
            if (temp & 1)
            {
                dbits[it]--;
                bits[it]--;
            }
            temp /= 2;
            it++;
        }
        result.push_back(max(next - curr + 1,1));
        curr++;
    }
    return result;
}
};