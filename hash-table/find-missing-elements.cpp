class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int> present(nums.begin(), nums.end());
        auto [min_it, max_it] = minmax_element(nums.begin(), nums.end());
        
        vector<int> result;
        for (int i = *min_it + 1; i < *max_it; ++i) {
            if (present.find(i) == present.end()) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};