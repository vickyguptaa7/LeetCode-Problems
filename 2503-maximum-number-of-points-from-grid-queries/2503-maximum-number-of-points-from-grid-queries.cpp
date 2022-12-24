class Solution
{
    public:
        vector<int> maxPoints(vector<vector < int>> &grid, vector< int > &queries)
        {
            vector<int> sortQuery;

            set<int>sset(queries.begin(), queries.end());
            for(auto &x:sset)
            {
                sortQuery.push_back(x);
            }

            int r = grid.size(), c = grid[0].size(), qsize = sortQuery.size();

            vector<vector < int>> visit(r, vector<int> (c, 0));

            vector<int> moveX = { 0,
                0,
                1,
                -1
            }, moveY = { 1,
                -1,
                0,
                0
            };

            queue<pair<int, int>> que1,sque;

            map<int, int> answer;
            int limitIter = 0, cntr = 0;

            que1.push({ 0,0 });
            visit[0][0] = true;
            while (!que1.empty())
            {
                int size = que1.size();
                while (size--)
                {
                    auto x = que1.front().first;
                    auto y = que1.front().second;
                    que1.pop();
                    if (grid[x][y] >= sortQuery[limitIter])
                    {
                        sque.push({ x,y });
                    }
                    else
                    {
                        cntr++;
                        for (int i = 0; i < 4; i++)
                        {
                            int _x = moveX[i] + x, _y = y + moveY[i];
                            if (_x >= r || _y >= c || _x < 0 || _y < 0 || visit[_x][_y])
                                continue;
                            visit[_x][_y] = true;
                            que1.push({ _x,
                                _y });
                        }
                    }
                }
                if (que1.empty())
                {
                    answer[sortQuery[limitIter]] = cntr;
                    if (limitIter != qsize - 1)
                    {
                        limitIter++;
                        while (!sque.empty())
                        {
                            que1.push(sque.front());
                            sque.pop();
                        }
                    }
                }
            }
            while (limitIter < qsize)
            {
                answer[sortQuery[limitIter++]] = cntr;
            }
            vector<int> result;
            for (auto &x: queries)
            {
                result.push_back(answer[x]);
            }
            return result;
        }
};