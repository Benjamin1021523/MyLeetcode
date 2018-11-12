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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;

        head->next = sortList(head->next);
        auto temp = head;
        while(temp->next && head->val > temp->next->val){
            temp = temp->next;
        }
        if(!temp->next){
            temp->next = head;
            head = head->next;
            temp->next->next = NULL;
            auto h = head;
            while(h){
                cout << h->val << " ";
                h = h->next;
            }
            cout << endl;
            return head;
        }
        else{
            auto re = head->next;
            head->next = temp->next;
            temp->next = head;
            auto h = re;
            while(h){
                cout << h->val << " ";
                h = h->next;
            }
            cout << endl;
            return re;
        }
    }
};
/**
未完成
*/