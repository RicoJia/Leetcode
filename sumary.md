# Sumary
### String
- A Palindrome could be either odd, or even
- Manacher algorithm is really just expanding towards the two ends of a string. 

### DFS
In most cases, DFS is implemented in a recursive way. But there are also for-loop equivalents. 
**But for either implementation, the first step of designing a DFS is to figure out the output sequence of each iteration
then how to call the same process.** 
 - Don't worry too much about copy, etc. Implement it! 


#### number of islands. 
Just like your Fun Project. Use DFS. Note that in each DFS iteration, you're going to find a complete patch. 
  
### Dynamic Programming
The very definition is to use previous knowledge to compute a current value. So the key is to think how to build your way to each step. 
A typical problem is the [0-1 knapsack problem](https://www.youtube.com/watch?v=xCbYmUPvc2Q). And it can be easily implemented as a 2D array

**Key idea for DP:** Sometimes, even though the problem asks to go for one specific value, you might be able to build your sub-problems by going 
from 0 to that value. 

Actually, for the classic knapsack problem, you can use an 1d array to solve the problem, bottoms up

```c++
int knapsack(int val[], int wt[], int n, int W)
{   //val[] are values, wt[] are weights, n is the number of items, W is target weight. 
    int dp[W+1];
    memset(dp, 0, sizeof(dp));
    for(int i=0; i < n; i++) 
        for(int j=W; j>=wt[i]; j--)
            dp[j] = max(dp[j] , val[i] + dp[j-wt[i]]);
    return dp[W];
}
```

Reason why this algorithm works:
1. knapsack requires you to be able to
  - keep best values of their corresponding weights as they are if your current weight is higher.   
  - your max value will be max(old_value(target_weight), item_value+old_value(target_weight - item_weight))
2. bottom up approach allows you to: 
  - not touch best values if your current weight is higher (j>=wt[i])
  - allows you to read old_value(target_weight), dp[j] and old_value(target_weight - item_weight)), (dp[j-wt[i]])), since this is 
  bottom up approach. 
  
#### Basic Set up for Graph Problems: 
1. build a lookup table, a "status_board", then do DFS and flip signs
like in [here](graph/0547-Friend-Circles)
 - Traversing thru a tree is similar to DFS, you do dfs on each node, 
 and you store the status of each node in an array. DFS can return the "rest of the total cost" to you, so make use of that. 
 Better method is required. See [here](graph/1376-Time-Needed-to-Inform-All-Employees)
  
####Distance To the Nearest 0  
**1. Not so good solution** 
[Problem](https://leetcode.com/problems/01-matrix/)
```
[011111011]
```
You just need two passes to find the minimum value from one direction: left to right: [0,1,2,3,4...0, 1,2], right to left:[0,1,2...3,2,1,0,1,2]
Rationale is you get the min from both directions, which is to **improve** based on what you have. 

In the 2D case, you can check left, up, then right, down. 

But this is not so good, as you will have to treat cells on the edge separately, and **depending on if there have been 0 at all.** 

**2. Generic Solution - multi-source BFS**
1. so you start from all the 0s, update their neighbors, then search from those neighbors, to update their neighbors.
2. A queue can make the search depth under control: you push all 0 positions first, then 1st layer neighbors, then 2nd layer neighbors.
3. Push cells to the queue if their cell values are changed.   

#### Backtracking
permutation and combination both can be expressed as DFS. 

#### Experiences
1. [Amazon OA19 Max of Mins](actual_test/Amazon_OA_19_Max_of_Min_Altitutes/README.md)

### BFS 
#### Distance To the Nearest 0  
[Problem](https://leetcode.com/problems/01-matrix/)
you can use a queue and keep adding and popping nodes to achieve BFS. The rationale is similar to the [DP solution ](#Distance-To-the-Nearest-0)
which is: you will get the right result after evaluating by getting the best of multiple passes. 
In 1D case, in each pass you evaluate 1 by starting from the 0 on the left/on the right. This is same as DP, which evaluates from 0 on the left & on the right as well.   
  
### Graph 

#### Topological Sort
https://leetcode.com/problems/course-schedule-ii/

Used in Software IDE build system, apt-get (packaging tool)

#### Bi-partition Problems: 
If a problem asks you to classify two types of nodes, and adjacent nodes cannot be in the same color, then it's bi-partition. 

![](Media/Bipartition.png)
The solution is: 
1. build a **FULL edge list** (half edge list is you only have node 1 -> node 2, but not 
node 2 -> node 1. ). A full edge list can gurantee all connected nodes are traversed,,
while a half edge list cannot. E.g, 0 -> 5, 5->2.    
2.  Use **DFS** for this problem. Otherwise, there will be too bugs for you to consider!!

Therefore, we are able to traverse thru all connected nodes from one DFS pass. This makes sure that 
we can start with a random color every time we want to color our pallet, since they're not connected. 
Corner case: empty edge list. 

#### Cycle Detection
You can have 2 methods: topological sort, or building 2 edge lists (one with inbound and one with outbound edges). 
Then, you can start popping edges on one edge list, from all leaf nodes. If there are no edge left at the end, the graph is clear. 
``

#### Hash Map
**if you work with random IDs, do not use std::vector. use std::unordered_map instead.**
Note that for unordered_map, you shouldn't use .at, but []

### Tree
1. Don't worry about ptrs. But also it might be hard to test them
2. BST concept is very important: left val < root < right val. 
3.  In the real thing debugging a tree is very cumbersome, (your job sometimes is to make a tree, from an array!) 
but you can debug at least some peripherals. 
4. Binary search: use [left, size - 1]; [left, mid - 1], [mid + 1, right]; return condition: 
l > r return null. 

#### Heap 
1. Heap is
    ```
       10(0)
        /  \
     5(1)  3(2)
    /   \
   4(3) 1(4)
   ```
Therefore, the root is either larger/smaller than the two children. If you heapify a heap, that's what it is. 
Say you have an array that represent heap (root = vec[i], left = vec[2*i + 1], right=[2 * i +2]). 
To heapify, You'll start from the non-leaf nodes (size/2-1), swap them so that the root is the largest. 

Then, trace down the affected tree. 

```c++
#include <algorithm>
std::make_heap(vec.begin(), vec.end(), [](int a, int b){return a < b; }) //so this is a max heap. 
std::pop_heap() //will pop the first element of a heap, then sort. you need to erase the last element of the vector. 
std::push_heap() //will also sort the heap. 
```
std::make_heap does that. O(n) , not O(nlg(n)). for a single heapify operation, it's o(lg(n)). 

2. Heap sort:      
pop, sort heap, pop, sort heap ...

## Useful Tips
1. Take whiteboard marker, eraser, pens, resumes to avoid las pendejadas. Nobody cares about your performance except for yourself. 
2. Quickselect... The partitioning algorithm is too hard to implement. Try the simple one (heap) first, and mention that in your comment. 
**This is because they sometimes just want to see how you think, not exactly how good your code is.**
3. Do not say: can I do DP? Like you're asking for permission. You should discuss alternatives. 
4. Usually, you don't have to worry about overflow. If that happens, use / instead of *, use - instead of +. 

## Tips for your career
1. Make your work public, and advertise it. The validation of your work is important. 
2. **Do the work that has a clear market-value goal!!**. Then, **do well so that people can count on you**.
That's how you make an impact. 