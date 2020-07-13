### Time 120 min

### Method 1- Binary Sort
Well, this is a pretty typical binary sort problem. O(log(n)) time complexity is a clear indicator of 
binary sorting. Also, you have an upper bound and lower bound.
Note that we first find the index of one of the target using binary sort. 

Then, we find the min index and max index using the index found number. Note that we can use the previous binary sort
to get a close estimation of upper and lower bounds. 

**I think this is very efficient, compared with many online solutions even if they appear shorter. Many of them do not fully make use of the bound estimates 
from the first binary sort.**
 

### Notes
the corner cases are:
- nums = {1}, target = 0
- nums = {5,7,7,8,8,10}; target = 6;

