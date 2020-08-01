### Time 20 min

### Method 1
This method, a no brainer, is to find an element suddenly gets smaller.

### Method 2
Divide and conquer. 
```[0,1,2,4,5,6,7] => [4,5,6,7,0,1,2]
4<5, 6<7, 0<1, 2 => 4< 6, 0 < 2; => 4>0 
so 0 is the odd one out!!
So that translates to the invariant: first half is always < the second half.  
```

Surprisingly, my [previous implementation](../0153-find-minimum-in-rotated-sorted-array ) is slightly faster. 
I guess that time is from accessing an element in a vector and unnecessarily copying a vector.

