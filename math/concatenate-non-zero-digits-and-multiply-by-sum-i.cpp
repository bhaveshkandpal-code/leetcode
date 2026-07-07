class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> st;
        int sum = 0, mx = INT_MIN;

        for (int x : nums) {
            mx = max(mx, x);
            if (x > 0) st.insert(x);
        }

        for (int x : st) sum += x;

        return sum == 0 ? mx : sum;
    }
};