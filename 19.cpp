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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *pre = NULL;
        ListNode *mid = head;
        ListNode *last = head;
        int count = 1;
        while (count < n) {
            last = last->next;
            count++;
        }
        if (last->next == NULL) {
            head = head->next;
            free(mid);
            return head;
        }
        else {
            while (last->next != NULL) {
                if (pre == NULL) 
                    pre = head;
                else 
                    pre = pre->next;
                
                mid = mid->next;
                last = last->next;
            }
            pre->next = mid->next;
            free(mid);
            return head;
        }
    }
};