### Time 53 min

### Method 1 - Double Pointers or DFS Backtracking
```
Input: n = 4, k = 2
Output:
[
  [2,4],     [1 | 2, 3, 4]
  [3,4],     [2 | 3, 4]
  [2,3],     [3 | 4]
  [1,2],
  [1,3],
  [1,4],
]
```
when you have k = 2, You can use a double pointer, or back tracking. 
However, when you have k > 2, the n-fold pointer way is simply not possible. Therefore, use DFS backtrracking . 