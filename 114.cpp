class Solution {
    public:
        void flatten(TreeNode* root) {
            flatten1(root);
        }

        TreeNode* flatten1(TreeNode* root) {
            if (root == NULL)
                return NULL;
            
            TreeNode* ptr1 = flatten1(root->left);
            TreeNode* ptr2 = flatten1(root->right);

            root->left = NULL;
            root->right = ptr1;

            TreeNode* ptr = root;

            while (ptr->right != NULL)
                ptr = ptr->right;
            
            ptr->right = ptr2;

            return root;
        }
};