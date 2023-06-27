bool mycomp(vector<int> &a, vector<int> &b)
{
    return a[1] < b[1];
}
bool mycomp2(pair<int, int> &a, pair<int, int> &b)
{
    return a.second < b.second;
}

class Solution {
public:
vector<int> countServers(int n, vector<vector<int>> &logs, int x, vector<int> &queries)
{
    vector<int> result;
    sort(logs.begin(), logs.end(), mycomp);
    vector<pair<int, int>> qr;
    for (int i = 0; i < queries.size(); i++)
    {
        qr.push_back({queries[i], i});
    }
    sort(qr.begin(), qr.end());
    vector<int> mp(n + 1, 0);
    int prev = logs[0][1], lit = 0, qit = 0;
    int cntr = 0, pit = 0;
    while (lit < logs.size() || qit < queries.size())
    {
        if (lit == logs.size())
        {
            // query
            while (pit < logs.size() && qr[qit].first - prev > x)
            {
                if(pit+1!=logs.size())
                {
                    prev = logs[pit+1][1];
                }
                mp[logs[pit][0]]--;
                if (!mp[logs[pit][0]])
                    cntr--;
                pit++;
            }
            qr[qit].first = n - cntr;
            qit++;
        }
        else if (qit == queries.size())
        {
            break;
        }
        else
        {
            if (logs[lit][1] == qr[qit].first)
            {
                if (!mp[logs[lit][0]])
                    cntr++;
                mp[logs[lit][0]]++;
                lit++;
            }
            else if (logs[lit][1] < qr[qit].first)
            {
                if (!mp[logs[lit][0]])
                    cntr++;
                mp[logs[lit][0]]++;
                lit++;
            }
            else
            {
                while (pit < logs.size() && qr[qit].first - prev > x)
                {
                    if(pit+1!=logs.size())
                    {
                        prev = logs[pit+1][1];
                    }
                    mp[logs[pit][0]]--;
                    if (!mp[logs[pit][0]])
                        cntr--;
                    pit++;
                }
                qr[qit].first = n - cntr;
                qit++;
            }
        }
    }
    sort(qr.begin(), qr.end(), mycomp2);
    for (int i = 0; i < qr.size(); i++)
        result.push_back(qr[i].first);
    return result;
}
};