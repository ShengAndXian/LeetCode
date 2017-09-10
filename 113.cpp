class Solution {
    public:
        vector<vector<int>> pathSum(TreeNode* root, int sum) {
            vector<vector<int> > res;
            vector<int> v;

            path(root, sum, 0, res, v);

            return res;
        }

        void path(TreeNode* root, int sum, int currentSum, vector<vector<int> >& res, vector<int> v) {
            if (root == NULL)
                return;

            currentSum += root->val;
            v.push_back(root->val);
            
            if (sum == currentSum && !root->left && !root->right) {
                res.push_back(v);                
                return;
            }
            
            path(root->left, sum, currentSum, res, v);
            path(root->right, sum, currentSum, res, v);
        }        
};