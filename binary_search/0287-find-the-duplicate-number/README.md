### Time 20 min

### Method 1: count sort. 
Easy solution, time and space complexity: O(n) and S(n). But this is not allowed as per the question. 

### Method 2: Binary Search 
The question says there could be more than 1 duplicate, and I didnt get this part the first time reading the question. Oops. 

Think about it, because the array is unsorted, you cannot have mid on the indices and do stuff on it. 
Instead, you should operate on the array ```[1...n]``` 
[1,3,4,2,2] =>mid = (1+4)/2 = 2. find the counts for these portions: left, mid. 
If mid == 2, return mid; else, if left < mid - 1. then you know mid has to be on the right. 
Therefore, count_l = 1, count_mid = 2, return mid; 
```
[1,2,3,4]
[3,1,3,4,2] => mid = 2, count_l= 1, count_mid =1, count_l == mid-1; left = mid+1 = 3, mid = 3, count_mid = 2
Because our left and right will be mid +/- 1, we do not get stuck in situations where left and right are always the same!!
```
- Corner cases
```
[2]
[2,2,2,2,2] =>left = 1, right = 4, mid = 2
```

