class Solution {
    public:
        RandomListNode *copyRandomList(RandomListNode *head) {
            if (!head)
                return NULL;
            
            if (m.find(head) == m.end()) {
                m[head] = new RandomListNode(head->label);
                m[head]->next = copyRandomList(head->next);
                m[head]->random = copyRandomList(head->random);
            }

            return m[head];
        }
    private:
        map<RandomListNode*, RandomListNode*> m;
};