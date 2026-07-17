class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> ans;
        int n = arr.size();

        for (int target = n; target >= 2; target--) {
            int idx = 0;
            while (arr[idx] != target) idx++;

            if (idx == target - 1) continue;

            if (idx != 0) {
                reverse(arr.begin(), arr.begin() + idx + 1);
                ans.push_back(idx + 1);
            }

            reverse(arr.begin(), arr.begin() + target);
            ans.push_back(target);
        }

        return ans;
    }
};