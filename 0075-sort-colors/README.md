Time 40 min
###Method 1
"Count sort": two pass solution: in the 1st pass, count how many 0, 1, 2 there are,then rebuild the vector. 
### Method 2
Rewrite the vector. In this specific case, you can push all 0s to one side and all 2s to the other. This can be done 
by swapping: if you encounter 0, swap to the left and go ahead. if you encounter 2, swap to the right and re-evaluate. 
- One tricky part is that: technically, you need to re-evaluate after you swap (left = 2, curr = 0) or (curr = 2, right = 0). However, the left pointer can only point to 0,1 (all 2 will be swapped out after current pointer). 
Therefore the only re-evaluation case is (left = 2, curr = 0), and this can be done when you hit a 2. 
### Additional Info
Back_inserter: it is an output iterator that is used to insert at the end of a container. **THE CONTAINER NEEDS TO HAVE PUSH_BACK()** 