# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2, carry = False):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if not l1 and not l2:
            if carry:
                return ListNode(1)
            return None
        if not l1:
            l1, l2 = l2, l1
        if not l2:
            l1.val += int(carry)
            carry = l1.val > 9;
            if carry:
                l1.val -= 10
                l1.next = self.addTwoNumbers(l1.next, None, carry)
            return l1
        else:
            l1.val += l2.val + int(carry)
            carry = l1.val > 9
            if carry:
                l1.val -= 10;
            l1.next = self.addTwoNumbers(l1.next, l2.next, carry)
            return l1