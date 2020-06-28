### Time 100 min

### Method 1 - No Regular Expression
2 things have to be done: 
1. find the first non-space character, and check if it were number or '+' or '-'.
    - Output 0 if the first char character is not number
2. for each char, 
    1. check if it's number
    2. **check if it's less than int_max - 10 * current_number** 
    
### Notes
* Check if a char is a digit: isdigit(char),  \<cctype\> 
* std::abs is in \<cmath\>
*  \<climits\> defines INT_MIN and INT_MAX
* Easy way to convert char to int: c - '0'
* **TRAP: abs(INT_MIN)!= -2^31, as INT_MAX = 2^31 - 1 and INT_MIN = -2^31**. This is also the tricky part of this problem. 
if negative, we cannot do (num - INT_MIN) * -1, since num initially is 0. 
For our purpose, **one clean way is**: (INt_MIN/INT_MAX - sign * c)/10 > current_number, where current_number is the absolute value of the 
number.  **So wheb working with overflowing, do division instead of multiplication, also do not do absolute value - classify negative and positive cases, there is no shortcut!**
