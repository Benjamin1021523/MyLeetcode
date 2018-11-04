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
    ListNode* reverseKGroup(ListNode* head, int k) {
        return change(head, k);
    }
private:
    ListNode* change(ListNode* head, int k){
        if(!check(head, k)){
            return head;
        }

        int i = k;//k還要傳所以不能直接改
        auto ans = head;//回傳的指標(應該指著第k個節點)
        auto ori = head;//第一個節點，倒轉後會變成這k個的最後一個
        auto temp = head->next;//記錄下個該去的節點
        while(--i){//head算一個
            head = temp;//跳到原本的下一個
            temp = head->next;//記錄下個該去的節點
            head->next = ans;//複寫next，所以上面才用temp先記錄
            ans = head;//往後指一個
        }
        //此時ans指著第k個節點
        ori->next = change(temp, k);//最後一個指向下一段的第一個

        return ans;
    }
    bool check(ListNode* head, int k){//確認剩餘長度充足
        while(k){
            if(!head)
                break;
            head = head->next;
            --k;
        }
        return k == 0;
    }
};