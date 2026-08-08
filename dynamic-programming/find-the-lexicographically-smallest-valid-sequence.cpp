class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> last(m, -1);

        // last[j] = latest position in word1
        // from which word2[j...] can start matching
        int i = n - 1, j = m - 1;

        while (i >= 0 && j >= 0) {
            if (word1[i] == word2[j]) {
                last[j] = i;
                j--;
            }
            i--;
        }

        vector<int> ans;
        bool usedMismatch = false;
        j = 0;

        for (i = 0; i < n && j < m; i++) {

            // Exact match
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            }

            // Use our one allowed mismatch
            else if (!usedMismatch &&
                     (j == m - 1 || i < last[j + 1])) {
                ans.push_back(i);
                usedMismatch = true;
                j++;
            }
        }

        if (j == m)
            return ans;

        return {};
    }
};