class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_set<long long> st;

        for (auto &p : points) {
            long long key = ((long long)p[0] << 32) | (unsigned int)p[1];
            st.insert(key);
        }

        int ans = INT_MAX;
        int n = points.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];

                if (x1 == x2 || y1 == y2) continue;

                long long p1 = ((long long)x1 << 32) | (unsigned int)y2;
                long long p2 = ((long long)x2 << 32) | (unsigned int)y1;

                if (st.count(p1) && st.count(p2)) {
                    ans = min(ans, abs(x1 - x2) * abs(y1 - y2));
                }
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};