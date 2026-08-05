class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> graph(n);
        vector<bool> suspicious(n, false);

        for (auto &e : invocations)
            graph[e[0]].push_back(e[1]);

        function<void(int)> dfs = [&](int u) {
            suspicious[u] = true;
            for (int v : graph[u]) {
                if (!suspicious[v])
                    dfs(v);
            }
        };

        dfs(k);

        for (auto &e : invocations) {
            if (!suspicious[e[0]] && suspicious[e[1]]) {
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!suspicious[i])
                ans.push_back(i);
        }

        return ans;
    }
};