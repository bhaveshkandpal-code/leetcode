class Solution {
public:
    TreeNode* build(vector<int>& nums, int l, int r) {
        if (l > r) return nullptr;

        int maxi = l;
        for (int i = l + 1; i <= r; i++) {
            if (nums[i] > nums[maxi])
                maxi = i;
        }

        TreeNode* root = new TreeNode(nums[maxi]);
        root->left = build(nums, l, maxi - 1);
        root->right = build(nums, maxi + 1, r);

        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }
};