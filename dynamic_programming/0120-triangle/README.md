### Time 36 min


### Method 1 - Dynamic Programming
This is a **CLASSIC DP Problem**. You don't know what each route's final cost will be, but you know 
at each step, the final cost of the route depends on the cost from this step on, to the last route. 
```
     [2],    [2+3+5+1]
    [3,4],   [3+5+1, 4+5+1]
   [6,5,7], [6+1,5+1,7+3]
  [4,1,8,3]  
```
So min_ path_cost
= 2 + cost of all (2)
= 2 + min(3 + cost_of_all(3), 4 + cost_of_all(4))
cost_of_all(3) = min(6 + cost_of_all(6), 5 + cost_of_all(5))... 

so we can start from the second last row, evaluate each elements least cost.  and write it to the element. 
This way, we just need a for loop and O(0) extra space.           