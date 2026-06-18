# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        fast,slow = head, head

        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next

        l1, l2 = head, head
        while l2.next:
            l2 = l2.next

        prev,curr = None, slow

        while curr:
            temp = curr.next
            curr.next = prev
            prev = curr
            curr = temp

        

        while l2.next:
            temp = l1.next
            l1.next = l2
            l2 = l2.next
            l1 = l1.next
            l1.next = temp
            l1 = l1.next

