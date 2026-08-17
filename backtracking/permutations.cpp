class Solution {
public:
 void solve( int index,  vector<vector<int>>&ans, vector<int> nums){
    if (index >= nums.size()){
        ans.push_back(nums);
        return;
    }
    for ( int j = index;j < nums.size();j++){
        swap( nums[index],nums[j]);
         solve( index+1, ans ,nums);
          swap( nums[j],nums[index]);
    }
 }
    vector<vector<int>> permute(vector<int>& nums) {
        vector <vector<int>>ans;
        int index=0;
        solve( index, ans ,nums);
        return ans;
    }
};