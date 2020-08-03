### Time 18 min

### Method 1 Dynamic Programming
The question is to get the max difference: later element - first element 
If we are allowed to make modifications to the original vector, we can have an inplace solution, 
with extra s(1) space complexity. 
```
[7,1,5,3,6,4], max profit on each day: [....0] prev= 4 
=> [... -2, 0], prev = 6, => [...-1, -2, 0] prev = 3 => ...
```
See the pattern? 

- Corner cases
```
[]
```

### Method 2: Regular Iteration. 
Same time and space complexity. 
```
[0 ... ], min = 7 => [0, -6 ... ], min = 1 => [0, -6, 4 ...], min = 1, [0, -6,4, 2 ...] min = 1
```