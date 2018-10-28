class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        target = n;
        if(gogogo(head) == n)
            return head->next;
        return head;
    }
private:
    int gogogo(ListNode* now){
        if(!(now->next))
            return 1;
        else{
            int n = 1 + gogogo(now->next);
            if(n == target + 1){
                now->next = now->next->next;
            }
            return n;
        }
    }
    int target;
};