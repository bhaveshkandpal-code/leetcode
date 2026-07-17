class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> freq(mx + 1);
        for (int x : nums) freq[x]++;

        vector<long long> cntG(mx + 1);

        for (int g = mx; g >= 1; g--) {
            long long c = 0;
            for (int j = g; j <= mx; j += g)
                c += freq[j];

            cntG[g] = c * (c - 1) / 2;

            for (int j = g * 2; j <= mx; j += g)
                cntG[g] -= cntG[j];
        }

        vector<long long> pref(mx + 1);
        for (int i = 1; i <= mx; i++)
            pref[i] = pref[i - 1] + cntG[i];

        vector<int> ans;
        for (long long q : queries)
            ans.push_back(lower_bound(pref.begin() + 1, pref.end(), q + 1) - pref.begin());

        return ans;
    }
};