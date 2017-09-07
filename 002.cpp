class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> v1 , v2;
        while(l1 != NULL){
            v1.push_back(l1->val);
            l1 = l1->next;
        }
        while(l2 != NULL){
            v2.push_back(l2->val);
            l2 = l2->next;
        }
        int i = 0 , j = 0;
        vector<int> res;
        int carry = 0;
        while(i < v1.size() && j < v2.size()){
            int sum = v1[i] + v2[j] + carry;
            if(sum >= 10){
                res.push_back(sum - 10);
                carry = 1;
            }
            else{
                res.push_back(sum);
                carry = 0;
            }
            i++;
            j++;
        }
        while(i < v1.size()){
            int sum = v1[i] + carry;
            if(sum >= 10){
                res.push_back(sum - 10);
                carry = 1;
            }
            else{
                res.push_back(sum);
                carry = 0;
            }
            i++;
        }
        while(j < v2.size()){
            int sum = v2[j] + carry;
            if(sum >= 10){
                res.push_back(sum - 10);
                carry = 1;
            }
            else{
                res.push_back(sum);
                carry = 0;
            }
            j++;
        }
        if(carry == 1){
            res.push_back(1);
        }
        ListNode *ptr = NULL;
        ListNode *head = NULL;
        ListNode *pre = NULL;
        for(i = 0;i < res.size();i++){
            ptr = new ListNode(res[i]);
            if(head == NULL){
                head = ptr;
                pre = ptr;
            }
            else{
                pre->next = ptr;
                pre = ptr;
            }
        }
        return head;
    }
};