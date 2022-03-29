# my own sln. Better sln is https://leetcode.com/problems/linked-list-cycle-ii/discuss/1701128/C%2B%2BJavaPython-Slow-and-Fast-oror-Image-Explanation-oror-Beginner-Friendly
class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head: 
            return None
        # fast forward 
        fast = head
        slow = head 
        init = False
        while fast != slow or not init:
            init = True
            if fast.next is not None: 
                fast = fast.next 
            else:
                return None  
            if fast.next is not None: 
                fast = fast.next 
            else: 
                return None  
            slow = slow.next
        ptr = head 
        while ptr != slow: 
            ptr = ptr.next
            slow = slow.next
        return ptr

