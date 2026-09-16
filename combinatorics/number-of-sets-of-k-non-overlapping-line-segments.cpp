class Solution:
    def numberOfSets(self, n: int, k: int) -> int:
        MOD = 10**9 + 7

        # dp[j] = ways with j completed segments
        # prefix[j] = accumulated ways that can be extended
        dp = [0] * (k + 1)
        prefix = [0] * (k + 1)

        dp[0] = 1
        prefix[0] = 1

        for _ in range(1, n):
            new_dp = dp[:]

            for j in range(1, k + 1):
                # End a new segment at the current point.
                new_dp[j] = (dp[j] + prefix[j - 1]) % MOD

            dp = new_dp

            for j in range(k + 1):
                prefix[j] = (prefix[j] + dp[j]) % MOD

        return dp[k]