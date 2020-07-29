### Time 20 min

What needs to be done: 
1. see if there are loops in this graph, represented by edge list. If yes, then no result
2. Else, count distinct nodes, including the standalone ones. 
This, needs **Topological Sorting**

### Method1 - DFS
First, you need to check for every node, see if there is a cycle to it. If you have visited this node, 
skip this node. Therefore, you need to mark a node visited. To mark visited: use an unordered set.  **But in the question, it was clearly stated at the beginnning that you'll have consecutive nodes.**
When you check for cycles, use DFS. you follow the edges, if a node has been visited, that is fine, but if the node
is being visited, then there will be a cycle. 


### Notes
1. Instead of marking visited, visiting, have a vector. so **A good lesson is, if you can have a vector with numbered elements, do not use unconsecutive elements.**
2. Instead of separately evaluating if a node has been visited, you can just do it in dfs. This is valid
because dfs will not change status until hitting the bottom of the recursion.   



