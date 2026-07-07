class Solution {
public:
    long long sumAndMultiply(int n) {
        long long concat = 0;
        long long sum = 0;

        string s = to_string(n);

        for (char c : s) {
            if (c != '0') {
                int d = c - '0';
                concat = concat * 10 + d;
                sum += d;
            }
        }

        return concat * sum;
    }
};