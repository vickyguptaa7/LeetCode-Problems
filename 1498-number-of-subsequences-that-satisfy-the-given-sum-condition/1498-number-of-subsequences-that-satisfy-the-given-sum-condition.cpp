typedef long long ll;

class Solution
{
    public:
        ll sum(ll a, ll b, ll mod = 1e9 + 7)
        {
            return (a + b) % mod;
        }
    ll product(ll a, ll b, ll mod = 1e9 + 7)
    {
        return (((ll) a % mod) *((ll) b % mod)) % mod;
    }
    ll power(ll a, ll b, ll mod = 1e9 + 7)
    {
        ll result = 1;
        while (b != 0)
        {
            if (b & 1)
                result = product(result, a, mod);
            a = product(a, a, mod);
            b /= 2;
        }
        return result;
    }
    int numSubseq(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        ll result = 0;
        int left=0,right=nums.size()-1;
        while(left<=right)
        {
            if(nums[left]+nums[right]>target)
            {
                right--;
            }
            else
            {
                result=sum(result,power(2,right-left));
                left++;
            }
        }
        return result;
    }
};