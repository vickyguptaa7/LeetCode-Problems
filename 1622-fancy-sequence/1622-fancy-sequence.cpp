typedef long long ll;
ll mod = 1e9 + 7;

ll prod(ll a, ll b, ll mod = 1e9 + 7)
{
    return ((a % mod) * (b % mod)) % mod;
}

ll sum(ll a, ll b, ll mod = 1e9 + 7)
{
    return ((a % mod) + (b % mod)) % mod;
}

ll diff(ll a, ll b, ll mod = 1e9 + 7)
{
    return (((a % mod) - (b % mod)) % mod + mod) % mod;
}

ll binary_expo(ll a, ll b, ll mod = 1e9 + 7)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
        {
            res = prod(a, res);
        }
        a = prod(a, a);
        b /= 2;
    }
    return res;
}

ll divs(ll a, ll b, ll mod = 1e9 + 7)
{
    return prod(a, binary_expo(b, mod - 2));
}

class Fancy {
    vector<pair<ll, pair<ll, ll>>> arr;
    ll curr_mult;
    ll curr_sum;

public:
    Fancy()
    {
        arr.clear();
        curr_mult = 1;
        curr_sum = 0;
    }

    void append(long long val)
    {
        arr.push_back({val, {curr_sum, curr_mult}});
    }

    void addAll(long long inc)
    {
        curr_sum = sum(curr_sum, inc);
    }

    void multAll(long long mul)
    {
        curr_mult = prod(curr_mult, mul);
        curr_sum = prod(curr_sum, mul);
    }

    int getIndex(int idx)
    {
        if (idx >= arr.size())
            return -1;
        ll prd =  divs(curr_mult, arr[idx].second.second);
        ll add = diff(curr_sum, prod(arr[idx].second.first, prd));
        return sum(add, prod(prd, arr[idx].first));
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */