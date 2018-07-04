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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        size_t n1 = 0, n2 = 0;
        while(l1){
            n1 *= 10;
            n1 += l1->val;
            l1 = l1->next;
        }
        while(l2){
            n2 *= 10;
            n2 += l2->val;
            l2 = l2->next;
        }
        size_t total = n1 + n2;
        
        
        ListNode first(0);
        ListNode* t = &first;
        ListNode* re = t;
        while(1){
            t->val = total % 10;
            total /= 10;
            if(!total)
                break;
            ListNode* temp = new ListNode(0);
            t->next = temp;
            t = temp;
        }
        return re;
    }
};