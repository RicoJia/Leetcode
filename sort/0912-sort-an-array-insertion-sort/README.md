### Time 20 min

### Insertion Sort 
Insertion sort is a sorting algorithm that's similar to sorting your card in hand - have a 
sorted part, and insert the next card into the sorted part. 
It is in genereal O(n^2), best & worst cases are also O(n^2)

To facilitate the sorting, we can use binary insertion sort - use binary search. 
**Speed test: without binary search, this algorithm takes about 0.4s to execute. With binary searhc, it takes 0.04s. **
Also, we are going to use std::deque for faster insertion while being able to have random access to elements. 


### Note
1. you can do dq.insert(dq.end()), to insert an element. 
- this goes back to the very definition of back_inserter. ??

2. 

 