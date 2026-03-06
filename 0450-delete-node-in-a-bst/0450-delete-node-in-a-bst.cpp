/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return nullptr;
        if(key < root->val){
            root->left = deleteNode(root->left, key);
        }

        else if(key > root->val){
            root->right = deleteNode(root->right, key);
        }
        if (root->val == key) {
            if (!root->left && !root->right)
                return nullptr;
            if (!root->right)
                return root->left;
            if (!root->left)
                return root->right;
            TreeNode* succ = findMin(root->right);
            root->val = succ->val;
            root->right = deleteNode(root->right, succ->val);
        }
        return root;
    }
    TreeNode* findMin(TreeNode* root) {
        while (root->left)
            root = root->left;
        return root;
    }
};