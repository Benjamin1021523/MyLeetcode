/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2, carry = false) {
    if(!l1 && !l2){
        if(carry)
            return new ListNode(1);
        return null;
    }
    if(!l2){
        l2 = [l1, l1 = l2][0];//swap
    }
    if(!l1){
        l2.val += carry;
        carry = l2.val > 9;
        if(carry){
            l2.val -= 10;
            l2.next = addTwoNumbers(l1, l2.next, carry);
        }
        return l2;
    }
    else{
        l2.val += l1.val + carry;
        carry = l2.val > 9;
        if(carry)
            l2.val -= 10;
        l2.next = addTwoNumbers(l1.next, l2.next, carry);
        return l2;
    }
};