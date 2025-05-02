class Solution {
public:
    string pushDominoes(string dominoes) {
        map<int, char> mp;
        int last=-1;
        for (int i = 0; i < dominoes.size(); i++) {
            if (dominoes[i] != '.')
                mp[i] = dominoes[i];
            last=i;
        }
        if(last==-1)
            return dominoes;
        for (int i = 0; i < dominoes.size(); i++) {
            if (dominoes[i] != '.')
                continue;
            auto hi = mp.upper_bound(i);
            auto lo = mp.end();
            if (hi != mp.begin())
                lo = prev(mp.find(hi==mp.end()?last:hi->first));

            // cases
            // lo and hi both not exist : .
            if (lo == mp.end() && hi == mp.end()) {
                continue;
            }

            // lo does not exist
            // -> hi is l : l
            // -> hi is r : .
            else if (lo == mp.end()) {
                if (hi->second == 'L')
                    dominoes[i] = 'L';
                else
                    dominoes[i] = '.';
            }
            // hi does not exist
            // -> lo is l : .
            // -> lo is r : r
            else if (hi == mp.end()) {
                cout<<i<<" "<<lo->first<<"\n";
                if (lo->second == 'L')
                    dominoes[i] = '.';
                else
                    dominoes[i] = 'R';
            }
            // lo and hi at same distance
            // -> lo is l and hi is r : .
            // -> lo is r and hi is l : .
            // -> lo is l and hi is l : l
            // -> lo is r and hi is r : r
            else if (lo->first + hi->first == i * 2) {
                if (lo->second == 'L' && hi->second == 'R')
                    continue;
                else if (lo->second == 'R' && hi->second == 'L')
                    continue;
                else if (lo->second == 'R' && hi->second == 'R')
                    dominoes[i] = 'R';
                else
                    dominoes[i] = 'L';
            }
            // lo and hi at diff distance
            // -> lo close
            //   -> lo is l and hi is l : l
            //   -> lo is l and hi is r : .
            //.  -> lo is r and hi is l : r
            //.  -> lo is r and hi is r : r
            // -> hi close
            //   -> lo is l and hi is l : l
            //   -> lo is l and hi is r : .
            //.  -> lo is r and hi is l : l
            //.  -> lo is r and hi is r : r
            else {
                if (i - lo->first < hi->first - i) {
                    if (lo->second == 'L' && hi->second == 'R')
                        continue;
                    else if (lo->second == 'R' && hi->second == 'L')
                        dominoes[i] = 'R';
                    else if (lo->second == 'R' && hi->second == 'R')
                        dominoes[i] = 'R';
                    else
                        dominoes[i] = 'L';
                } else {
                    if (lo->second == 'L' && hi->second == 'R')
                        continue;
                    else if (lo->second == 'R' && hi->second == 'L')
                        dominoes[i] = 'L';
                    else if (lo->second == 'R' && hi->second == 'R')
                        dominoes[i] = 'R';
                    else
                        dominoes[i] = 'L';
                }
            }
        }
        return dominoes;
    }
};