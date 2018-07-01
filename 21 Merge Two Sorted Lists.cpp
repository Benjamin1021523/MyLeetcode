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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        
        ListNode* d;
        if(l1->val < l2->val){
            d = l1;
            l1 = l1->next;
        }
        else{
            d = l2;
            l2 = l2->next;
        }
        ListNode* re = d;
        while(l1 && l2){
            if(l1->val < l2->val){
                d->next = l1;
                l1 = l1->next;
            }
            else{
                d->next = l2;
                l2 = l2->next;
            }
            d = d->next;
        }
        if(l1)
            d->next = l1;
        else
            d->next = l2;
        return re;
    }
};