### Time 45 min

### Method 1 Dynamic Programming O(n2)
```
[10,9,2,5,3,7,101,18] => [...1] => [1+0,1] => [1+1,1,1], max_num for element >7  
=>[1+2,2,1,1] max_element for element>3= 2 => [1+2,3,2,1,1] max_num for element > 5
=> [1+3,3,3,2,1,1], max_element for element>2 = 3 =>[1+1, ....] max_num for element > 9 = 2.
```

### Method 2 Binary Search (nlog(n))


original array: [10,9,2,5,3,7,101,18]
index_of_last_element_of_particula_length: [-1, -1, ...]. Elements in this array are in an increasing order! 
max_length = 0; 
------------------------------------------------------------
i = 0: max_length =1, i_arr: Indices of ([10, -1...] )
i = 1: 9<10, max_length = 1, Indices of ([9, -1, ...])
i = 2: 2 < 9: max_length = 1: Indices of ([2, -1, ...])
i = 3: 5 > 2: max_length = 2: Indices of ([2, 5, -1, ...])
i = 4: 3 > 2: max_length = 2:Indices of ([2, 3, -1, ...])
i = 5: 7 > 3: max_length = 3 Indices of ([2, 3, 7, -1, ...])
i = 6: 101 > 7...


### Notes 
THe binary search of this problem is tricky. because you're searching for a range, not a number. Also, it should satisfy these conditions: 
1. [1,2,4], return 0 for input == 0, return 0 for input ==1, return 1 for input == 2, return  3 for input ==3, return 4 for input ==4, return 5 for input ==5. 
if you usemid,mid+1, you have to see if mid+1 will hit max_length. 
corner cases: [2,5], search for 3. 