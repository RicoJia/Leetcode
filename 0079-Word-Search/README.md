### Time 70 min
'
### Method 1 - One pass Hash Table (not working)
Build a hash map for each found element's neighbor - iterate thru all elements in the grid. 
**THIS IS NOT WORKING, because if there are two same letters, you don't know which one will lead to a complete string sequence. 
And if you pop an element, there is no way to go back. Try a different approach.**

### Method2 - One Pass BFS. (not working)
BFS is not a good solution. There is one simple scenario where simple BFS does not work: Suppose the word  is "ABCDEB", and the board is 

B1 A    B2 

E1 D1 C1


So the correct sequence is A B2 C1 D1 E1 B1. 

If we use BFS and  mark visited, we first expand A, and get B1, B2. Then we mark B1 visited and expand its neighbor, but we cannot find a C. We keep expanding B2 and its neighbors, until we hit B1. However, B1 has been marked visited. So we have a problem here. 

As you can see, a valid algorithm should be able to mark all the visited nodes of an invalid path back to unvisited. This requires back-tracking through depth. 


### Method3 - DFS 
This is very similar to my sawyer the picasso project. 
So, first we search the grid for the first matching letter. Once we find it, we have a fixed sequence to expand its neighbors. When we expand a node, we first mark it visited, then call the function again
to recursively expand, until we find the last node. If we cannot find any valid node from the current node's neighbors, we mark the current node unvisited and returns.  


### Notes
1. Lambda expression's return type is required when you have recursive calls within itself. 
- You also need 
```cpp
#include <functional> 
std::function <bool (args)>
``` 

2. Initialize a 2d vector
```cpp
        vector<vector<bool>> visited_table(1, vector<bool>(2, false));

```
3. To represent 4-connectivity: 
```cpp
        int r_inc[] = {-1, 0, 1};
        for (int& r_i: r_inc){
            if(0 <= r_i + i_r && r_i + i_r < max_row){
                vector<int> c_inc = (r_inc == 0)? (vector<int>){-1, 1}:(vector<int>){0};
```

4. DFS recursion: 
Do not pre-select which neighbor is valid -- let the neighbor decide for itself. 
Example: if you first rule out nodes that are out of bounds, there are cases where you might need to evaluate further and get a result but 
you skip the evaluation due to the pre-screening. 

So just don't do pre-screening, let the node evaluate itself. 