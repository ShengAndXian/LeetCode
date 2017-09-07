/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *new_head = head;
        ListNode *ptr1 = head;
        ListNode *ptr2 = NULL;
        ListNode *ptr3 = NULL;
        while (ptr1 != NULL) {
            ptr2 = ptr1->next;
            if (ptr2 == NULL)
                break;
            ptr1->next = ptr2->next;
            ptr2->next = ptr1;
            if (ptr3 != NULL)
                ptr3->next = ptr2;
            if (new_head == head)
                new_head = ptr2;
            ptr3 = ptr1;
            ptr1 = ptr1->next;
        }
        return new_head;
    }
};