class Solution {
    public:
        TreeNode* sortedListToBST(ListNode* head) {
            vector<int> v;

            while (head != NULL) {
                v.push_back(head->val);
                head = head->next;
            }

            return build(v, 0, v.size() - 1);
        }

        TreeNode* build(vector<int>& v, int start, int end) {
            if (start > end)
                return NULL;
            
            int mid = (start + end) / 2;
            TreeNode* node = new TreeNode(v[mid]);
            node->left = build(v, start, mid - 1);
            node->right = build(v, mid + 1, end);

            return node;
        }
};