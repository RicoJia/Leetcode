### Time 50 min

### Method 1 - Build a buffer heap
Making a heap (heapify) is O(klg(k)). Therefore, we can build a max heap, which will keep the smallest k elements at the moment. 
To sum up, best case time complexity is O(nk), worst case is O(nklg(k)).   

- Improvement: pop_heap and push_heap are both O(lg(n)). Therefore, you can push a new number to the heap, then pop it. this will be O(n * 2 * lg(k)) = O(nlg(k)) 

#Method 2 - Quick Select
Each time randomly select a number, then find its position. Based on the position, you can perform the same technique in a subarray.
Best case: O(1), normal case: O(nlg(n)). Worst case: O(n^2)  

This is similar to quick sort. 
In-place partition for quick sort is: 
```
[7,6,5,4,1,2,3], pivot is 3. [6,7*,5*,...] => [6,5,7*, 4*...] => [6,5,4,7*,...] =>
[6,5,4,7,1*,2*, 3] => [6,5,4,7,1*,2,3*] => [6,5,4,7,3,2,1] => return pos(3)
```
# Method 3 - Merge sort - Wouldn't work
we divide the array into 1 or 2-element pieces, get the min/max of the sub-arrays, until we have just enough numbers to get the min/max from. 
```
[3,2,1,5,6,4], k =2 => [3,2,1], [5,6,4] => [3],[2,1], [5], [6,4]. 
```
However, the min or maxes of the subarrays are not the k min or maxes of the array. This is why merge sort wouldn't work. 
### Notes
1. **Leetcode Specific: do not try to print stuff in your code for submission. Otherwise, when the test case is large, you will get "output limit exceeded" error. "**
