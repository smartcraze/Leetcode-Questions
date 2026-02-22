class Solution {
public:
    void buildParent(TreeNode* node, TreeNode* par ,unordered_map<TreeNode* ,TreeNode*> &parent_map){
        if(!node) return ;
        parent_map[node] = par;
        buildParent(node->left , node,parent_map);
        buildParent(node->right , node,parent_map);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* ,TreeNode*> parent;
        buildParent(root,nullptr ,parent);  // root ->parents
        
        unordered_set<TreeNode*> vis;
        queue<TreeNode*> q;

        q.push(target);
        vis.insert(target);
        int dist = 0;
        while(!q.empty()){
            if(dist == k) break;
            int size = q.size();

            for(int i = 0;i<size ;i++){
                TreeNode* curr = q.front();
                q.pop();

                if(curr->left && !vis.count(curr->left)){
                    vis.insert(curr->left);
                    q.push(curr->left);
                }
                if(curr->right && !vis.count(curr->right)){
                    vis.insert(curr->right);
                    q.push(curr->right);
                }
                if(parent[curr] && !vis.count(parent[curr])){
                    vis.insert(parent[curr]);
                    q.push(parent[curr]);
                }
            }
            dist++;
        }

        vector<int> result;
        while(!q.empty()){
            result.push_back(q.front()->val);
            q.pop();
        }
        return result;

    }
};