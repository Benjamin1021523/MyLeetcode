/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var reverseList = function(head) {
    let arr = [];
    arr.push(null);
    let cur = head;
    while(cur !== null){
        arr.push(cur);
        cur = cur.next;
    }
    for(let i = arr.length - 1;i > 0;i--){
        arr[i].next = arr[i-1];
    }
    return arr[arr.length - 1];
};
