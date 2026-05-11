
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& nums){
        if(!root) return ;
        inorder(root->left,nums);
        nums.push_back(root->val);
        inorder(root->right,nums);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> nums;
        inorder(root,nums);

        for(int i = 1; i<nums.size();i++){
            if(nums[i] <= nums[i-1]) return false;
        }
        return true;
    }
};


/* 

I needed to validate the Binary tree and i wanted to check if everythings is corect right 

if i would have went thourght the recureiosn it would be som uch tough and thinking 

The property which is the inorder traversal is sorted at last so i checked if the conditions fails it mean its not a validate tree

 */
