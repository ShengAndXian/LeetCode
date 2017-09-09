class Solution {
    public:
        vector<vector<int>> levelOrder(TreeNode* root) {
            vector<vector<int> > res;
            queue<TreeNode*> q;

            q.push(root);

            while (!q.empty()) {
                int num = q.size();
                vector<int> v;

                for (int i = 0;i < num;i++) {
                    TreeNode* node = q.front();
                    q.pop();
                    if (node != NULL) {
                        v.push_back(node->val);
                        q.push(node->left);
                        q.push(node->right);
                    }
                }
                
                if (!v.empty())
                    res.push_back(v);
            }

            return res;
        }
};