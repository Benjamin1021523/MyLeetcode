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
    ListNode *detectCycle(ListNode *head) {
        if(!head)
            return NULL;
        set<ListNode*> s;
        s.insert(head);
        s.insert(NULL);
        while(s.find(head->next) == s.end()){
            s.insert(head->next);
            head = head->next;
        }
        return head->next;
    }
};