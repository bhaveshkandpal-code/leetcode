class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> count;
        for (int x : nums) {
            count[x]++;
        }

        // Case 1: Subarray size is 1
        if (k == 1) {
            int ans = -1;
            for (auto& [val, freq] : count) {
                if (freq == 1) {
                    ans = max(ans, val);
                }
            }
            return ans;
        }

        // Case 2: Subarray size equals array length
        if (k == n) {
            int ans = -1;
            for (int x : nums) {
                ans = max(ans, x);
            }
            return ans;
        }

        // Case 3: 1 < k < n
        // Only nums[0] or nums[n-1] can potentially appear in exactly 1 subarray of length k.
        int ans = -1;
        if (count[nums[0]] == 1) {
            ans = max(ans, nums[0]);
        }
        if (count[nums[n - 1]] == 1) {
            ans = max(ans, nums[n - 1]);
        }

        return ans;
    }
};