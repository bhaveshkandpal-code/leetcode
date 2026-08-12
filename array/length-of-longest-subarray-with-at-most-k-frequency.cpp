class Solution {
public:
    double compressedMean(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long sum = 0;
        for (int i = 1; i < n - 1; i++)
            sum += nums[i];
        return (double)sum / (n - 2);
    }
};