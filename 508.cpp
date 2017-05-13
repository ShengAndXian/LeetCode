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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> v;
        GetSum(root , v);
        sort(v.begin() , v.end());
        int fre = 0;
        vector<int> res;
        for (int i = 0; i < v.size();) {
            int j = i + 1;
            while (j < v.size() && v[j] == v[i]) j++;
            int num = j - i;
            if (num > fre) {
                fre = num;
                res.clear();
                res.push_back(v[i]);
            }
            else if (num == fre) {
                res.push_back(v[i]);
            }
            i = j;
        }
        return res;
    }
    int GetSum(TreeNode *root , vector<int> &v) {
        if (root == NULL)
            return 0;
        int a = GetSum(root->left , v);
        int b = GetSum(root->right , v);
        v.push_back(a + b + root->val);
        return a + b + root->val;
    }
};