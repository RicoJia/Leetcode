### Time 20 min

### Method 1 - Semi-brute-force
The Peak valley method needs to be modified for this problem. For example, it needs to become 
something like: 1. finds all the increasing edges (if there is no restrctions, the max sum will be sum 
of all increasing edges, assuming you can buy and sell on the same day. ). 
Then, from all these edges, pick the two most increasing edges. You can combine consecutive ones 
to create a whole big edge.   
[3,3,5,0,0,3,1,4] => []


### Method 2- One pass Decision Flow
This method is mind-blowing... Still not entirely sure why ss always gives you the right result!
There may be multiple combinations of the best two transactions. 
So, we find fs: the best buying price for only one transaction. (not necessarily the first transaction in the best combos) 
fb: the best selling profit for one transaction. (not necessarily the first transaction in the best combos) 
sb: the best profit after buying, right after a transaction
ss: the best profit for the second sell! 

 
