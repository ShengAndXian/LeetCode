class Solution {
    public:
        vector<TreeNode*> generateTrees(int n) {
            vector<TreeNode*> res;

            if (n == 0)
                return res;
                
            return generate(1, n);
        }

        vector<TreeNode*> generate(int start, int end) {
            vector<TreeNode*> res;

            if (start > end) {
                res.push_back(NULL);
                return res;    
            }

            for (int i = start;i <= end;i++) {
                vector<TreeNode*> v1 = generate(start, i - 1);
                vector<TreeNode*> v2 = generate(i + 1, end);

                for (int j = 0;j < v1.size();j++) {
                    for (int k = 0;k < v2.size();k++) {
                        TreeNode* node = new TreeNode(i);
                        node->left = v1[j];
                        node->right = v2[k];
                        res.push_back(node);
                    }
                }
            }

            return res;
        }
};