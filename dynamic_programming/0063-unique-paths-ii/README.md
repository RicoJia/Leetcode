### Time 50 min

### Method 1 Dynamic Programming
I observed starting from the bottom right, every cell's value will be the sum of right and left cells.
To start with, the bottom cell has the value one. 

In terms of traverse order, I am going to follow the square wavefront order, instead of backtracking. 
So the from bottom to the second last one in the column. then, from right to the second left-most cell in the top row. Finally, the top-left corner. 
when the cell value is 1, I'm going to change it to 0.   
```
  [0,0,0]
  [0,1,0]
  [0,0,0]
```

### Note
Challenge: the numbers will over flow. because, the top left cell will be like fibonacci!!
