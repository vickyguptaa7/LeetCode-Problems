
typedef long long ll;

ll sum(ll a, ll b, ll mod = 1e9 + 7)
{
    return (a + b) % mod;
}

ll diff(ll a, ll b, ll mod = 1e9 + 7)
{
    return ((a - b) % mod + mod) % mod;
}

ll product(ll a, ll b, ll mod = 1e9 + 7)
{
    return (((ll)a % mod) * ((ll)b % mod)) % mod;
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

class DString_Hash
{
    vector<pair<ll, ll>> hash, inv_pow, pow;
    ll size, base, mod1, mod2;

public:
    DString_Hash(string s)
    {
        // use random value to avoid soln hacking of hasing
        base = 107;
        // set the prime mod val use random big prime to avoid hacking of soln
        mod2 = 1e9 + 21;
        mod1 = 1e9 + 7;
        size = s.size() + 1;
        hash.resize(size);
        inv_pow.resize(size);
        pow.resize(size);
        // precalc the power and inveerse power
        preCalc();
        // pre calc the hashes
        buildHash(s);
    }
    void preCalc()
    {
        pow[0].first = 1;
        pow[0].second = 1;
        for (int i = 1; i < size; i++)
        {
            pow[i].first = product(pow[i - 1].first, base, mod1);
            pow[i].second = product(pow[i - 1].second, base, mod2);
        }
        inv_pow[0].first = 1;
        inv_pow[0].second = 1;
        pair<ll, ll> pw_inv;
        pw_inv.first = power(base, mod1 - 2, mod1);
        pw_inv.second = power(base, mod2 - 2, mod2);

        for (int i = 1; i < size; i++)
        {
            inv_pow[i].first = product(inv_pow[i - 1].first, pw_inv.first, mod1);
            inv_pow[i].second = product(inv_pow[i - 1].second, pw_inv.second, mod2);
        }
    }
    void buildHash(string s)
    {
        hash[0].first = 0;
        hash[0].second = 0;
        for (int i = 1; i < size; i++)
        {
            // s[i-1]-'a' +1 bcoz for a val bcoz 0 and product remains 0 so we a to be 1
            hash[i].first = sum(hash[i - 1].first, product(s[i - 1] - 'a' + 1, pow[i - 1].first, mod1), mod1);
            hash[i].second = sum(hash[i - 1].second, product(s[i - 1] - 'a' + 1, pow[i - 1].second, mod2), mod2);
        }
    }
    pair<ll, ll> getHash(int l, int r)
    {
        // 1 based indexing
        pair<ll, ll> hres;
        hres.first = diff(hash[r].first, hash[l - 1].first, mod1);
        hres.first = product(hres.first, inv_pow[l - 1].first, mod1);

        hres.second = diff(hash[r].second, hash[l - 1].second, mod2);
        hres.second = product(hres.second, inv_pow[l - 1].second, mod2);

        return hres;
    }
};


class Solution {
public:
    int strStr(string haystack, string needle) {
        DString_Hash s1(haystack),s2(needle);
        int k=needle.size();
        auto hash1=s2.getHash(1,k);
        for(int i=k;i<=haystack.size();i++)
        {
            auto curr=s1.getHash(i-k+1,i);
            if(hash1.first==curr.first&&hash1.second==curr.second)
            {
                return i-k;
            }
        }
        return -1;
    }
};