### Time 100 min

### Method 1 - Divide and Conquer

if n is even, we break n down to the product of x^1 and X ^ 0;
if n is odd, we still break n down to the product of x^1.  
if n is negative, make n positive and use the above two
However, there are **SO MANY BUGS!!**

#### Modifications

1. How about overflow? While |x|>1 and large n is something you cannot handle, |x|< 1 and large n is 
something you can. 
    - Do myPow(x * x) or myPow(1.0/x, - n). **This way, you can always evaluate x^n before going all the way 
    down to x^1 or x^0, which is impossible to reach** 
    - Accordingly, have a separate case for x ==1, x == 0 so you can handle large n
    - since INT_MIN = -2147483648 and INT_MAX = 2147483647, for n < 0, you have to shift n to -2147483647 range. 