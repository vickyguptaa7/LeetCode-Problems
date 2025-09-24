class Solution {
public:
    string fractionToDecimal(int num, int deno) {
        bool isNuNegative = num < 0;
        bool isDeNegative = deno < 0;
        bool isNegative = isNuNegative && isDeNegative
                              ? false
                              : (isNuNegative || isDeNegative);

        long long numerator = abs((long long)num);
        long long denominator = abs((long long)deno);

        string part1 = to_string(numerator / denominator);

        numerator = numerator % denominator;

        if (numerator == 0)
            return to_string(isNegative?-stol(part1):stol(part1));

        string part2;

        map<int, int> mpp;
        numerator *= 10;
        do {
            if (numerator < denominator) {
                mpp[numerator] = part2.size();
                numerator *= 10;
                part2 += "0";
                continue;
            }
            mpp[numerator] = part2.size();
            part2 += to_string(numerator / denominator);
            numerator = numerator % denominator;
            numerator *= 10;
        } while (numerator != 0 && !mpp.count(numerator));

        if (mpp.count(numerator))
            part2 = part2.substr(0, mpp[numerator]) + "(" +
                    part2.substr(mpp[numerator]) + ")";

        part1 = isNegative ? "-" + part1 : part1;
        return part1 + "." + part2;
    }
};