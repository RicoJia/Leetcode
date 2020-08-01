### Time 40 min

### Method 1
Rolling Window: wouldn't work. Multiple pointers: might work. 
You have 
```
[]
[1] 
[2] [1,2]
[3] [1,3], [2,3],[1,2,3]
[4] [1,4], [2,4], [3,4], [1,2,4], [1,3,4], [2,3,4], [1,2,3,4]
[n], [1,n],[2,n], [1,2,n], [3,n], [1,3,n] ...
```
Can you find the pattern? You keep adding a new number, to all the previous sets!!

So, first you need to reserve enough space for this. In total, you have 1 + (2^0 + 2^1 + ... 2^(vec.size() - 1)) = 2^(vec.size()). 

### Method 2.  (TODO) DFS
1. DFS will take 
    1. the starting index you'd like 
    2. target size of the array
2. DFS will 
    1. push the array to the return array, if it's  full 
    2. iteratively call the dfs, with the same size, but the next starting index
    
### Additional: try permutation
 Based on method 2, since the order of elements matter, we have an additional array for storing the "usage status" of elements - 
 we first set an element as used, then push other elements in the array, then set the element as false. 
 Then, we build an array for every single element.   