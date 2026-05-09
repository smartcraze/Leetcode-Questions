
class Solution {
public:
    void bfs(TreeNode* root, vector<double>& ans){
        
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            double sum = 0;
            for(int i = 0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                sum+=node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            double avg = sum/size;
            ans.push_back(avg);
        }
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if(!root) return ans;
        bfs(root,ans);
        return ans;
    }
};