### Time 30 min

### Method 1 - Build a buffer heap
Making a heap (heapify) is O(klg(k)). Therefore, we can build a max heap, which will keep the smallest k elements at the moment. 
To sum up, best case time complexity is O(nk), worst case is O(nklg(k)).   

- Improvement: pop_heap and push_heap are both O(lg(n)). Therefore, you can push a new number to the heap, then pop it. this will be O(n * 2 * lg(k)) = O(nlg(k)) 

#Method 2 - Quick Select
Each time randomly select a number, then find its position. Based on the position, you can perform the same technique in a subarray.
Best case: O(1), normal case: O(nlg(n)). Worst case: O(n^2)  

### Notes
1. **Leetcode Specific: do not try to print stuff in your code for submission. Otherwise, when the test case is large, you will get "output limit exceeded" error. "**
