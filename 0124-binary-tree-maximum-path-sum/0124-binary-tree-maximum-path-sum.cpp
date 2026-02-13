class Solution {
public:
    int solve(TreeNode* root, int &maxsum){
        if(!root) return 0;
        int left = max(0, solve(root->left, maxsum));
        int right = max(0, solve(root->right, maxsum));
        int currPath = left + right + root->val;
        maxsum = max(maxsum, currPath);
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        int maxsum = INT_MIN;
        solve(root, maxsum);
        return maxsum;
    }
};
