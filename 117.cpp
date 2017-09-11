class Solution {
    public:
        void connect(TreeLinkNode *root) {
            TreeLinkNode* ptr = root;

            while (ptr != NULL) {
                TreeLinkNode* ptr1 = ptr;

                TreeLinkNode* pre = NULL;

                while (ptr1 != NULL) {
                    if (ptr1->left != NULL) {
                        if (pre != NULL)
                            pre->next = ptr1->left;
                        
                        pre = ptr1->left;
                    }

                    if (ptr1->right != NULL) {
                        if (pre != NULL)
                            pre->next = ptr1->right;
                        
                        pre = ptr1->right;
                    }

                    ptr1 = ptr1->next;
                }

                ptr1 = ptr;
                ptr = NULL;

                while (ptr1 != NULL) {
                    if (ptr1->left != NULL)
                        ptr = ptr1->left;
                    else if (ptr1->right != NULL)
                        ptr = ptr1->right;
                    
                    if (ptr != NULL)
                        break;
                    
                    ptr1 = ptr1->next;
                }
            }
        }
};