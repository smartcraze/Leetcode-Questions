class Solution {
public:

    int xDepth, yDepth;
    TreeNode* xParent;
    TreeNode* yParent;

    void dfs(TreeNode* node, TreeNode* parent, int depth, int x, int y){

        if(!node) return;

        if(node->val == x){
            xDepth = depth;
            xParent = parent;
        }

        if(node->val == y){
            yDepth = depth;
            yParent = parent;
        }

        dfs(node->left, node, depth+1, x, y);
        dfs(node->right, node, depth+1, x, y);
    }

    bool isCousins(TreeNode* root, int x, int y) {

        dfs(root, NULL, 0, x, y);

        return (xDepth == yDepth) && (xParent != yParent);
    }
};
