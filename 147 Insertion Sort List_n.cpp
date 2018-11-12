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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* re = new ListNode(0);
        
        re->next = head;
        return call(head);
    }
private:
    ListNode* call(ListNode* head){
        if(!head || !head->next)
            return head;
        return insert(head, call(head->next));
    }
    ListNode* insert(ListNode* ins, ListNode* lis){
        ins->next = NULL;
        auto re = new ListNode(0);
        re->next = lis;
        if(ins->val <= lis->val){//插在頭
            ins->next = lis;
            auto t = ins;
            while(t){
                cout << t->val << " ";
                t = t->next;
            }
            cout << endl;
            return ins;
        }
        while(lis){
            if(!lis->next){//加在末尾
                lis->next = ins;
                break;
            }
            if(ins->val > lis->val){//還沒找到插入點
                lis = lis->next;
                continue;
            }
            if(ins->val <= lis->next->val){//插在中間
                ins->next = lis->next;
                lis->next = ins;
                break;
            }
        }
        auto t = re->next;
        while(t){
            cout << t->val << " ";
            t = t->next;
        }
        cout << endl;
        return re->next;
    }
};
/**
未完成
*/