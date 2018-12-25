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
    void reorderList(ListNode* head) {
        if(!head)   return;
        vector<ListNode*> v;
        while(head){
            v.push_back(head);
            head = head->next;
        }
        int n = v.size();
        for(int i = 1;i <= n / 2;++i){
            v.insert(v.begin()+i*2-1, v[v.size()-i]);
        }
        v.resize(n);
        for(int i = 0;i < n-1;++i){
            v[i]->next = v[i+1];
        }
        v[n-1]->next = NULL;
    }
};