### Time 120 min

### Method 1 - Divide and Conquer
we are going to find the position of the root, then the left root, finally the right root. 
For any subtree, 1. the first node in pre-order is the root. 2, the left subtree is from the left boundary to the root in in-order
3. the right sub-tree is the portion in pre-order from left subtree end to the end.   


###Notes

1. Traversing a binary tree has three method: 
    1. in order: print left tree of the current root -> current root -> right tree of the current root -> the left tree of the left child  ....
    2. Postorder: left tree of the current root -> right tree of the current root -> root
    3. Preorder: root -> left tree -> right tree
    
    Example:
     
    ![](../../Media/binary_tree.gif)
    1. In-order Traversal: 4 -> 2 -> 5 -> 1 -> 3
    2. Preorder: 1 -> 2 -> 4 -> 5 -> 3
    3. Postorder: 4 -> 5 -> 2 -> 3 -> 1
  

2. **In leetcode, auto is not allowed in function prototype.** Therefore, you need std::vector<type>::const_iterator for that. 

3. Implementation notes
    - divide and conquer can be squeezed into one function if the difference of the two parts can happen only in arguments. 
    - Be careful with the two array's starting and ending conditions. They might be symmetrical 
    - gdb does not work with vector iterators so well. Fix it!  
        - Well, maybe the iterator you pass in was not the right type? It's actually fine. 

4. Try using template instead of iterator to implement this. 
    - It is actually incredibly simple. You just do template<class It> ... 
    We can do this because template functions can be defined only in h file, and we're working in h file. 
    (for link time template instantiation)
    