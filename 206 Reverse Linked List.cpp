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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)
            return head;
        auto re = head;
        while(head){
            data.push_back(head->val);
            head = head->next;
        }
        auto w = re;
        for(int i = data.size()-1;i >= 0;--i){
            w->val = data[i];
            w = w->next;
        }
        return re;
    }
private:
    vector<int> data;//stack意外的比較慢
};