class Solution {
    public:
        void reorderList(ListNode* head) {
            vector<ListNode*> v;
            ListNode* ptr = head;
            int n = 0;

            while (ptr) {
                v.push_back(ptr);
                n++;
                ptr = ptr->next;
            }

            ptr = head;

            for (int i = 0;i < n / 2;i++) {
                v[n - 1 - i]->next = ptr->next;
                ptr->next = v[n - 1 - i];
                ptr = ptr->next->next;
            }
            
            if (ptr)
                ptr->next = NULL;
        }
};