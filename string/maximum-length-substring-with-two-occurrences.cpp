class Solution {
public:
    int solve(string &s, int l, int r, vector<int> &freq) {
        if (r == s.size())
            return 0;

        freq[s[r] - 'a']++;

        if (freq[s[r] - 'a'] > 2) {
            freq[s[l] - 'a']--;
            return solve(s, l + 1, r, freq);
        }

        int curr = r - l + 1;

        return max(curr, solve(s, l, r + 1, freq));
    }

    int maximumLengthSubstring(string s) {
        vector<int> freq(26, 0);
        return solve(s, 0, 0, freq);
    }
};