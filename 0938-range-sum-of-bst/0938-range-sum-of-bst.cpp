class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        stack<TreeNode*> st;
        st.push(root);

        int sum = 0;

        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();

            if(node == NULL)
                continue;

            if(node->val >= low && node->val <= high)
                sum += node->val;

            if(node->val > low)
                st.push(node->left);

            if(node->val < high)
                st.push(node->right);
        }

        return sum;
    }
};
