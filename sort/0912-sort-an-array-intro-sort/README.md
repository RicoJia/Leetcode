### Time 80 min

Introsort is a hybrid sorting algorithm that incorporates insertion sort, quick sort, and heap sort. 
Each algorithm's average and worst case time complexities are: 
insertion sort O(n^2), O(n^2). Quicksort is O(nlg(n)), O(n^2) (where the pivot is always the smallest or the largest element). 
heap sort is O(nlg(n)), O(nlg(n)) (disadvantage is even though the array is sorted, you need to spend O(nlgn) time to build the 
heap, you still need nlg(n) to build the heap, then another nlg(n) to pop each element off the heap and resort.).

Merge sort is not considering here because it is not in-place. 

Principle: 
1. For short array n <= 16, we use insertion sort.  
2. For long array, we first try quicksort. However, if we have to go too deep into the recursion, we need to use heap sort. 

Experiments: Not significant speed boost. 

### Method 1 - Quick Sort
To specify an array, we need to get start, end.  
### Method 2 - Heap Sort
A key insight in a binary heap is that the parent's children's indices are 2*i+1, 2*i+2 

Source: geeksforgeeks.com 
```
Input data: 4, 10, 3, 5, 1
         4(0)
        /   \
     10(1)   3(2)
    /   \
 5(3)    1(4)
```

Because each layer has 2^(n -1) elements. Therefore, if index i = 2^(n) - 1 + p, then its child
will be 2^(n+1) - 1 +2*p = 2 * i + 1, 2* i+2. 

First, you build the heap, from the bottom to the top(i.e, find a root and its two children, get the largest one)
- Do you want partial heap? (that is, go from bottom tot the top once, without looking at the sub-heap again). 
Answer is no. Because after swapping the top with a leaf node, you might end with this: 
```
Input data: 4, 10, 3, 5, 1
         4(0)
        /   \
     5(1)   3(2)
    /   \
 6(3)    1(4)
```
- Bug: do you want to swap root with left child, then the new root with right child? No. Because the old left child will be the new right child. 
but there's no gurantee that the left child is larger than the right child!

Finally, you swap the top with a bottom leaf node, heapify from the top to bottom 
- Another key insight here is when you go from bottom to top, you just need to evaluate starting at 
n/2-1. This actually starts from the last leaf node's parent, and go thru all the previous nodes.  

Use a struct greaters() to have a similar interface as std::make_heap() function.  

### Notes
The tricky part of this project is **Integration**. I pretty much copied and pasted my old code, which were individually correct. (tested with different depths)
Therefore, something is wrong in integration. 
I tested the code with only depth=1, to see what'd happen if there's only one quick sort run. 
Turned out it's the heapification - the entire set up was for [0, size), not for [start, end). So I spent an hour, just remapping stuff. 