class Solution {
    public:
        vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            vector<vector<int> > res;

            if (root == NULL)
                return res;
                
            queue<TreeNode*> q;
            int flag = 0;

            q.push(root);

            while (!q.empty()) {
                int num = q.size();
                vector<int> v;
                
                for (int i = 0;i < num;i++) {
                    TreeNode* ptr = q.front();
                    q.pop();

                    if (ptr->left) 
                        q.push(ptr->left);
                    if (ptr->right)
                        q.push(ptr->right);

                    v.push_back(ptr->val);
                }

                if (flag == 1)
                    reverse(v.begin(), v.end());
                
                res.push_back(v);
                flag = flag == 0 ? 1 : 0;
            }

            return res;
        }
};