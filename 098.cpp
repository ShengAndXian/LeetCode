class Solution {
    public:
        bool isValidBST(TreeNode* root) {
            vector<int> v;

            inorder(root, v);

            for (int i = 0;i < v.size();i++) {
                if (i > 0 && v[i] <= v[i - 1])
                    return false;
            }

            return true;
        }

        void inorder(TreeNode* root, vector<int>& v) {
            if (root == NULL)
                return;
            
            inorder(root->left, v);
            v.push_back(root->val);
            inorder(root->right, v);
        }
};