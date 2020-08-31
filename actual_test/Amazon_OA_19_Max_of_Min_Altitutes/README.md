### Time 47 min

DP: ->, -> down,
if hitting bottom/head, return. 
else, find the max of its down, right children, then compare itself with them. 

Then update it.  


## Feedback
It took me 5 min to finalize on my thoughts on this, but it ended up taking me 47 min to get rid of all the 
**bugs!!**
Big ones
1. segfault **Due to infinite loop**
2. not familiar with int reference: int&  
3. mistook max of all mins with min of all maxes. 
4. at first I thought just updating the grid is fine - but if you want the max of all of them,
then you need a separate variable! a grid can only tell you elements from the subsequent cells.

Small ones
1. return the wrong element (at first I thought just updating the grid is fine - but if you want the max of all of them,
then you need a separate variable! a grid can only tell you elements from the subsequent cells.)

Success Stories
1. When using gdb to debug, I printed out the row, cln number, which helped quite a bit. 