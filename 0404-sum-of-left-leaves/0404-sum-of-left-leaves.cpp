class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        solve(root,sum);
        return sum;
    }
    void solve(TreeNode* root, int &sum){
        if(!root) return;
        if(root->left != nullptr && root->left->left ==nullptr && root->left->right == nullptr) sum+=root->left->val;
        solve(root->left,sum);
        solve(root->right,sum);
    }
};