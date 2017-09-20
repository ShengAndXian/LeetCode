class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        iterator = nullptr;
        
        while (root) {
            st.push(root);
            root = root->left;
        }

        if (!st.empty()) {
            iterator = st.top();
            st.pop();
        }
    }

    bool hasNext() {
        return iterator ? true : false;
    }

    int next() {
        int res = iterator->val;
        TreeNode *ptr = iterator->right;

        while (ptr) {
            st.push(ptr);
            ptr = ptr->left;
        }

        if (st.empty()) {
            iterator = nullptr;
        }
        else {
            iterator = st.top();
            st.pop();
        }

        return res;
    }
private:
    TreeNode *iterator;
    stack<TreeNode*> st;
};