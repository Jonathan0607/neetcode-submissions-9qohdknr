# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeNodes(self, list1, list2) -> ListNode:
        l1 = list1
        l2 = list2
        
        start = ListNode(0)
        curr = start
        while l1 and l2:
            if l1.val <= l2.val:
                curr.next = l1
                l1 = l1.next
            else:
                curr.next = l2
                l2 = l2.next
            curr = curr.next
        curr.next = l1 or l2
        
        return start.next


    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if len(lists) < 1:
            return ListNode().next
        while len(lists) > 1:
            lists[0] = self.mergeNodes(lists[0], lists.pop(1))
        return lists[0]