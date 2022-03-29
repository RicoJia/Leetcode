# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        #Optional?
        H = None
        h = head
        for i in range(left-1): 
            H = h
            h = h.next
        
        T = h.next        
        for i in range(right - left): 
            T = T.next
        
        for i in range(right - left + 1): 
            # print(T.val)
            temp = h.next
            h.next = T
            T = h
            h = temp
            
        if H: 
            print(H.val)
            H.next = T
        else: 
            head = T
        return head
