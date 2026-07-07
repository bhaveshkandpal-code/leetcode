class Solution {
public:
    long long concatAndMultiply(int n) {
        vector<int> digits;

        while (n > 0) {
            if (n % 10 != 0)
                digits.push_back(n % 10);
            n /= 10;
        }

        reverse(digits.begin(), digits.end());

        long long concat = 0, sum = 0;
        for (int d : digits) {
            concat = concat * 10 + d;
            sum += d;
        }

        return concat * sum;
    }
};