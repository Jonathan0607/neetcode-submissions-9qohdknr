# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head
        slow = head
        mid = head.next
        fast = head.next.next
        head.next = None
        while fast:
            mid.next = slow
            slow = mid
            mid = fast
            fast = fast.next
        mid.next = slow
        return mid