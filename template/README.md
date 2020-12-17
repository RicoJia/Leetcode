### Time 60 min
Shortest path. The most difficult part is: DFS only tells you 
which nodes have been visited, but not if that path is the shortest or not. 
In this problem, we assume signal is being emmited simultaneously, so 
we need to consider the parallelism here. 

You cannot use native DFS. 

###Notes
For edge list, I ended up spending lots of time debugging
1. vector dimension was wrong (It was 11:00pm lol)
 - Causing function type do not match issues 
2. You can write out the big elements. 
3. Array accessing was wrong - wrong dimension.
4. *Unfamiliar: std::any_of is in algorithm (.begin(), .end(), predicate)* 
5. *Unfamiliar: v.erase(iterator)*
6. **The biggest mistake: Didn't realize all signals can travel in parallel, hence you get the shortest path any point to another, then get the 
max from all of them.**
 
 7. **DO NOT USE MEMSET**
 8. You can use ptr in std::algorithm functions. 

