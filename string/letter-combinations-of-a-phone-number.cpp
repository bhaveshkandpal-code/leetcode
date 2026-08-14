class Solution {
public:
    void solve(string &digits, int idx, string curr, vector<string>& ans) {
        if (idx == digits.size()) {
            ans.push_back(curr);
            return;
        }

        string mp[] = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        string letters = mp[digits[idx] - '0'];

        for (char ch : letters) {
            curr.push_back(ch);
            solve(digits, idx + 1, curr, ans);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;

        if (digits.empty())
            return ans;

        solve(digits, 0, "", ans);

        return ans;
    }
};