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
    bool hasCycle(ListNode *head) {
        if(!head)
            return false;
        ListNode* one = head;
        ListNode* two = head;
        while(one && two && two->next){
            one = one->next;
            two = two->next->next;
            if(one == two)
                return true;
        }
        return false;
    }
};