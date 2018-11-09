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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return head;
        h = head;
        target = k;
        walk(head);
        if(ok)
            return ans;
        else
            return head;
    }
    int walk(ListNode* head){
        ++length;
        int re;
        if(!head->next){
            target %= length;
            last = head;
            return 0;
        }
        else
            re = 1 + walk(head->next);//+1是為了match到更前一個
        if(re == target){//下一個就是新的頭時
            last->next = h;//原頭尾串接
            ans = head->next;
            head->next = NULL;//下一個變成新的頭，這個就變成新的尾了
            ok = 1;
        }
        return re;
    }
private:
    ListNode* h, *ans, *last;//原本的頭、新的頭、原本的尾(可能要接上頭)
    int length = 0;//數串列長度
    int target;//目標值，算完總長度之後取mod
    bool ok = 0;//是否交換過
};