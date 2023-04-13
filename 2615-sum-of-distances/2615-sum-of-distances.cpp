class Solution
{
    public:
        vector < long long > distance(vector<int> &nums)
        {
            map<int, vector < int>> list;
            for (int i = 0; i < nums.size(); i++)
            {
                list[nums[i]].push_back(i);
            }
            vector < long long > result(nums.size(), 0);
            for (auto indxArr: list)
            {
                long long sufSum = accumulate(indxArr.second.begin(), indxArr.second.end(), 0ll);
                int eleCnt = indxArr.second.size();
                long long preSum = 0;
                for (int i = 0; i < indxArr.second.size(); i++)
                {
                    sufSum -= indxArr.second[i];
                    if(i!=0)
                        result[indxArr.second[i]] += (i*1ll*indxArr.second[i] - preSum);
                    if(i+1!=indxArr.second.size())
                        result[indxArr.second[i]] += (sufSum - (eleCnt - i - 1ll) *indxArr.second[i]);
                    preSum += indxArr.second[i];
                }
            }
            return result;
        }
};