/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode removeElements(ListNode head, int val) {
        if(head != null){
            if(head.val == val){
                return removeElements(head.next, val);
            }
            else{
                head.next = removeElements(head.next, val);
                return head;
            }
        }
        return null;
    }
}
