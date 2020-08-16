### Time 20 min

### Method 1 - 3D DP
```
strs = ["10","0001","111001","1","0"], m = 5, n = 3 => output = 4
strs = ["10","0","1"], m = 1, n = 1 => output = 2

How many look ups do you need? 
    (0,0), (0,1), (1,0), (1,1) ... (m,n) (m+1)*(n+1)
"10"
"0"
"1"
```
### Notes
1. How to do tuple arithmatic? 
use std::valarray. You can do something like 
```
valarray<int> varr{1,2}; 
varr[0]; 
```
**You should use 3D vector, otherwise, if you use an unordered_map, this container does not work with valarray in c++17!!**

2. how to get the number of 0s and 1s of a string?  
```

int sum = std::accumulate(varr.begin(), varr.end(), 0, [](int sum, char& c){return sum + c - '0'; });

```

### Method 2 - 2D DP - Bottom up
```
m\n  0, 1,  2,  3
0    
1       1   1   1
2       1   1   1
3       1   1   1
4       1   2   2
5   1    2   3   3
```
go from the bottom right corner, all the way to the current index of the string. 