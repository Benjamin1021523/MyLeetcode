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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return NULL;
        auto ans = lists[0];
        for(int i = 1;i < lists.size();++i){
            ans = merge(ans, lists[i]);
        }
        return ans;
    }
private:
    ListNode* merge(ListNode* a, ListNode* b){
        if(!a)
            return b;
        if(!b)
            return a;

        if(a->val > b->val)
            swap(a, b);
        auto re = a;
        auto now = a;

        a = a->next;
        while(a || b){
            if(!a){//小的一串沒了，後面串大的
                now->next = b;
                break;
            }
            if(!b){//沒有大的要比較，照上一次now指向a就行了
                break;
            }

            if(a->val > b->val)
                swap(a, b);//確保a[0]的值最小
            now->next = a;//記錄到要回傳的list中
            now = now->next;//下一次寫到下一個
            a = a->next;//下一次拿新的a[0]去比
        }

        return re;
    }
};