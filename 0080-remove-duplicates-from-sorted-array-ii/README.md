### Time 25 min
https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

### Method 1 - easy
remove the element if it's the same as the first 2. 

### Method 2 - copy valid elements over. 
2 pointers, to_copy is vec[1], to_be_copied is vec[2]. if to_be_copied != to_copy or to_be_copied!= to_copy -1, then we know to_copy+1 can be replaced.
The tricky part is, what if to_copy+1 is different than to_copy? Well, since to_be_copied starts out being to_copy+1, if we increment to_copy when to_be_copied!= to_copy, then we do not have
to_copy+1 == to_copy. 

Beautiful
https://github.com/pezy/LeetCode/tree/master/079.%20Remove%20Duplicates%20from%20Sorted%20Array%20II 

### Notes
1. Delete an element by index in array
```vec.erase(vec.begin() + 1); ```
2. **Tricky Part**: vec.size()-2: this can be 2^64-1 when vec.size() == 1, because vec.size() is unsigned integer!
3. Theoretically Faster: Use std::remove compared to vector::erase()
    - vector::erase() is to physically deallocate a memory location, then copy all subsequent elements one by one
    - std::remove do not physically anything. Instead, it checks all elements in a range and move all good elements to the front, then return a new iterator to the end of the container. 
    - **However on leetcode it's slower!!**


