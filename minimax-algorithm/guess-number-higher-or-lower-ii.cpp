class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int len = 2; len <= n; len++) {
            for (int l = 1; l + len - 1 <= n; l++) {
                int r = l + len - 1;
                dp[l][r] = INT_MAX;

                for (int k = l; k <= r; k++) {
                    int left = dp[l][k - 1];
                    int right = dp[k + 1][r];

                    dp[l][r] = min(dp[l][r],
                                   k + max(left, right));
                }
            }
        }

        return dp[1][n];
    }
};