class Solution {
    public:
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            int index = -1;

            return build(preorder, index, inorder, 0, inorder.size() - 1);
        }

        TreeNode* build(vector<int>& preorder, int& index, vector<int>& inorder, int start, int end) {
            if (start > end)
                return NULL;
            
            index++;

            int i;

            for (i = start;i <= end;i++)
                if (inorder[i] == preorder[index])
                    break;
                
            TreeNode* node = new TreeNode(preorder[index]);
            node->left = build(preorder, index, inorder, start, i - 1);
            node->right = build(preorder, index, inorder, i + 1, end);

            return node;
        }
};