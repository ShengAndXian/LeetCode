class Solution {
    public:
        int sumNumbers(TreeNode* root) {
            int res = 0;

            sum(root, "", res);

            return res;
        }

        void sum(TreeNode* root, string s, int& res) {
            if (root == NULL)
                return;

            s.append(1, root->val + '0');

            if (root->left == NULL && root->right == NULL) {
                int t;
                stringstream ss(s);

                ss >> t;
                res += t;
                
                return;
            }

            sum(root->left, s, res);
            sum(root->right, s, res);
        }
};