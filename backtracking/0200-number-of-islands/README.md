### Time 75 min

### Method: 
DFS: keep going up/down, until there's no island

###Note:
**DFS Important: since you don't want to traverse the nodes you've traversed, you need to mark them. Otherwise, you will get
infinite loops, which might give you segfault.** 

There are several small mistakes, such as: 
1. wrote a = b as a == b
2. !(a == 0 && b == 0) as (a!=0 && b!=0)
3. 4 connectivity: r+c==-1 || r+c ==1