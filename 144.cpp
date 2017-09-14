class Solution {
    public:
        vector<int> preorderTraversal(TreeNode* root) {
            vector<int> res;
            stack<TreeNode*> st;
            TreeNode* ptr = root;

            while (true) {
                while (ptr) {
                    res.push_back(ptr->val);
                    st.push(ptr);
                    ptr = ptr->left;
                }

                if (st.empty())
                    break;
                
                ptr = st.top();
                st.pop();
                ptr = ptr->right;
            }

            return res;
        }
};