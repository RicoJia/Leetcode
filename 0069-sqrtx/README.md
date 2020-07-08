### Time 65 min

###Method 1 - Binary Search With Bit Shifting
1. First, find the binary representation of a number, let n = number of its bits. If it has one digit (0,1), return itself.
    - e.g, 9 is 1001, has 4 bits. n = 4
2. find the lower bound of its square root, which is 2^((n-1)/2), or 1<<((n-1)/2). Its upper bound = lower bound + 1
    - e.g, for 9, lower bound is (1<<(4-1)/2) = (1<<1) = 2, upper bound is 3. 
3. find middle number of upper and lower bounds. If num == lower bound^2 or upper_bound == lower bound + 1, return lower bound. 
Else, calculate the next upper and lower bound using the binary search way. 
    
###Notes: 
1. One tricky part is: **std::bitset does not have an effective way to count MSB.**
 Therefore, you need to manually shift bits and see if the number is 0.  
