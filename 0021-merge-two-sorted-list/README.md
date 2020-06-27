#time (40 min)
## Thoughts
This is my second attempt for this problem. In  first attempt, I tried to make a new array and try to make copy of each 
element. That's not as spatially efficient. 

## Additional info
1. in C++, std::list is a doubly-linked list with the bidrectional iterator (of course, no random access iterators). 
std::forward list is a singly-linked list with the forward iterator. 
2. use if(ptr) to see if ptr is still valid; 
3. Assign a pointer using ternary: ListNode* ptr = l1?l1:l2
## TODO: 
Use Recursion for this. 