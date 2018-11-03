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
        ListNode* ans = new ListNode(0);
        int carry = 0;
        ListNode* nod = ans;

        while(l1 || l2){
            //ListNode* a = new ListNode(0);
            //nod->next = a;
            //這樣寫會雙重釋放記憶體，必須讓宣告的變數只給自己用
            if(!l1){
                nod->next = new ListNode((l2->val + carry) % 10);
                carry = (l2->val + carry) / 10;
                l2 = l2->next;
                nod = nod->next;
            }
            else if(!l2){
                nod->next = new ListNode((l1->val + carry) % 10);
                carry = (l1->val + carry) / 10;
                l1 = l1->next;
                nod = nod->next;
            }
            else{
                nod->next = new ListNode((l1->val + l2->val + carry) % 10);
                carry = (l1->val + l2->val + carry) / 10;
                l1 = l1->next;
                l2 = l2->next;
                nod = nod->next;
            }
        }
        if(carry){
            nod->next = new ListNode(carry);
        }
        return ans->next;
    }
};