class Solution {
    public:
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> res;
            stack<TreeNode*> st;
            TreeNode* ptr = root;

            while (true) {
                while (ptr != NULL) {
                    st.push(ptr);
                    ptr = ptr->left;
                }

                if (st.empty())
                    break;
                    
                ptr = st.top();
                st.pop();
                res.push_back(ptr->val);
                ptr = ptr->right;
            }

            return res;
        }
};