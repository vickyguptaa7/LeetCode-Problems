class Solution
{
    public:
        vector<int> majorityElement(vector<int> &nums)
        {
            pair<int, int> num1 = {0,0},num2={0,0};
            
            for (int i = 0; i < nums.size(); i++)
            {
                if (num1.first == nums[i])
                {
                    num1.second++;
                }
                else if (num2.first == nums[i])
                {
                    num2.second++;
                }
                else if (num1.second==0)
                {
                    num1 = { nums[i],1};
                }
                else if (num2.second==0)
                {
                    num2 = { nums[i],1};
                }
                else
                {
                    num1.second--;
                    num2.second--;
                }
            }
            num1.second = 0;
            num2.second = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                if (num1.first == nums[i]) num1.second++;
                if (num2.first == nums[i]) num2.second++;
            }
            vector<int> ans;
            if (num1.second > nums.size() / 3) ans.push_back(num1.first);
            if (num2.second > nums.size() / 3&&num1.first!=num2.first) ans.push_back(num2.first);
            return ans;
        }
};