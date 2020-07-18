### Time 80 min

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

