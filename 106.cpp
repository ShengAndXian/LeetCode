class Solution {
    public:
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            int index = postorder.size();

            return build(postorder, index, inorder, 0, inorder.size() - 1);
        }   

        TreeNode* build(vector<int>& postorder, int& index, vector<int>& inorder, int start, int end) {
            if (start > end)
                return NULL;
            
            index--;

            int i;

            for (i = start;i <= end;i++) 
                if (inorder[i] == postorder[index])
                    break;
                
            TreeNode* node = new TreeNode(postorder[index]);
            node->right = build(postorder, index, inorder, i + 1, end);
            node->left = build(postorder, index, inorder, start, i - 1);

            return node;
        }
};