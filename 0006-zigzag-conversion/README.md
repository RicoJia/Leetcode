### Time 100 min

### Method 1 - Parse thru each row
We try to find the pattern for each element in a row. 
1. row 0: 0, 0 + (row_num -1)* 2 , 0 + (row_num - 1) * 2 +  (row_num +1) * 2...
    2. row 1: 1,  1 + (row_num -2 )* 2, 1 + (row_num -2) * 2 + (2 -1)*2 , 1 + (row_num - 2)*2 + (row_num -1)*2 
3. row m: m, m + (row_num - m -1 ) * 2, m + (row_num - m -1 ) * 2 + (m)* 2 ... 

Therefore, for each row, we calculate the element indices using this formula
- Several things worth noticing: 
    1. when 

### Notes
1. string.at() can be used for indexing. 


### Method 2 - [see here](https://github.com/pezy/LeetCode/blob/master/005.%20ZigZag%20Conversion/solution.h)
THIS IS CRAZY - ONE PASS SOLUTION. It's surprisingly straightforward - you construct a vector of strings, each string is a row. 
Based on the remainder ```i%(numRows - 1)```, you can add each character by moving up or down. When the ```i/(numRows-1)``` is odd, you should move down, 
by starting to add chars from the top row; else, start from the bottom row. 
 
- Notes:
    1. you can concatenate a string to another string. However, you cannot concatenate a char array to another. 
    E.g, this is valid: ``` string a = "lol"; lol+ char_or_char_arr```; this is not valid: ```string a = "lol" + "aaa"; ```
    2. another way to represent odd number: ```n & 0x1```
    3. ternary can be used for appending/other actions, too. E.g, 
    ```cpp
     (n & 0x1 ? ret[nRows-m-1] : ret[m]) += s[i];
    ```