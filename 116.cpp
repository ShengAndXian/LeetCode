class Solution {
    public:
        void connect(TreeLinkNode *root) {
            TreeLinkNode* ptr = root;

            while (ptr != NULL) {
                TreeLinkNode* ptr1 = ptr;

                while (ptr1 != NULL && ptr1->left != NULL) {
                    ptr1->left->next = ptr1->right;

                    if (ptr1->next != NULL)
                        ptr1->right->next = ptr1->next->left;
                    
                    ptr1 = ptr1->next;
                }

                ptr = ptr->left;
            }
        }
};