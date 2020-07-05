### Time 48 min

### Method 1 - Use a hash map to store node's addresses

### Method 2 -Floyd's Cycle Detection Method, using fast and slow pointers
Key Insight: Let n be the number of nodes outside the loop, the loop has p nodes. 
If the fast ptr is one step faster than the slow ptr, 
1. The slow ptr and the fast ptr will stop at the same node in a loop.  
2. Let m be the distance from the list start to the  stopping point of the fast & slow ptr, 
the head is also m steps away from the head.  Therefore, just make the head and slow ptr advance the same number of steps 
will help you find the start! 

**Advantage: no extra space needed**

### Note: 
1. hash set: if you just wanna see if something has appeared, use this. 
2. **when you get space efficiency, be ready for the loss of time complexity.**







