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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, bool carry = false) {
        //改用遞迴
        if(!l1 && !l2){
            if(carry)
                return new ListNode(1);
            return NULL;
        }
        if(!l2){
            swap(l1, l2);
        }
        if(!l1){
            l2->val += carry;
            carry = l2->val > 9;
            if(carry){
                l2->val -= 10;
                l2->next = addTwoNumbers(l1, l2->next, carry);
            }
            return l2;
        }
        else{
            l2->val += l1->val + carry;
            carry = l2->val > 9;
            if(carry)
                l2->val -= 10;
            l2->next = addTwoNumbers(l1->next, l2->next, carry);
            return l2;
        }
    }
};