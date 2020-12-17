### Time 20 min

### Method 1 - easy, but not working for inputs longer than 32 bits. 
get binary number from the strings, then add them together

### Method 2 - Easy
Use carry to add numbers together. 

### Notes
1. c++ has std::to_string for int, float...
2. Tricky part: print out int -> binary -> string. You need to consider order. 
3. if you're using log2, you need to consider i = 0. 
4. I changed the testing framework - I'll just use an int main instead, as it will be more compatible with gdb. 
