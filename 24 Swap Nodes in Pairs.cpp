class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!(head) || !(head->next))
            return head;
        auto record = head->next;
        head->next = swapPairs(head->next->next);
        record->next = head;
        return record;
    }
};