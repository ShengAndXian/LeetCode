/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        vector<int> v;
        Inorder1(root , v);
        int sum = 0;
        for (int i = v.size() - 1; i >= 0; --i) {
            sum += v[i];
            v[i] = sum;
        }
        int n = 0;
        Inorder2(root , v , n);
        return root;
    }
    void Inorder1(TreeNode *root , vector<int> &v) {
        if (root == NULL)
            return;
        Inorder1(root->left , v);
        v.push_back(root->val);
        Inorder1(root->right , v);
    }
    void Inorder2(TreeNode *root , vector<int> &v , int &n) {
        if (root == NULL)
            return;
        Inorder2(root->left , v , n);
        root->val = v[n];
        n++;
        Inorder2(root->right , v , n);
    }
};