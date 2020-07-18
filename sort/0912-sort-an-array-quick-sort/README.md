### Time 20 min

### Quick Sort
First pick the last element of the array, then traverse thru all elements in the array, and find the 
element's position in the array. 
Then, find two subarrays using the element as a pivot. Repeat the same thing, until a subarray's size becomes one. 

- Bug: Do you think you can simply swap the pivot element with the element at the actual pivot position, then continue on your 
quicksort? No. You not only need to find the actual pivot position, swap, but also partition the array. 

**check how other people do their partition!!**

- My naive thought for partitioning is to create another array, throw elements in there and do copy. It's also O(n), but copy might take quite some time. 
On [geeksforgeeks.com](https://www.geeksforgeeks.org/quick-sort/), they have a pretty cool two-pointer one-pass, in-place partition 
algo. Check it out.   
    1. **BUG**: when taking the two-pointer approach, do you want to swap the to_swap_i without checking whether or not 
    it's smaller than the pivot element? No. You want to make sure you can actually swap the element. 
    One way of doing so is increment *to_swap_i* with the faster pointer, and pause *to_swap_i* if it sees an element that can be swapped with.  