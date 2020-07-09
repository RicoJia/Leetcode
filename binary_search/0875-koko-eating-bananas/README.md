### Time 70 min

### Method 1 - Binary Search
#### What type of questions can use Binary Search? 
When you have an upper bound and a lower bound, and you wanna find a value right in the middle, 
you use binary search. 

Initially, we have a natural upper bound, the max number in piles, and a lower bound, int(sum/num of piles). 
Then we can recursively decrease this range, until lower bound and upprt bound are right next 
to each other. The upper bound can always make sure Koko is able to finish early/ on time. the lower bound does not. 

#### Corner cases
1. When there's only one element, Koko should eat at ceil(element/H)
2. When H is greater than the number of piles, but that's really not a concern here as we don't return 
bool. 
3. There are cases where k = 4, 5,6.... all yield the same result. In that case, you need to evaluate once
h <= H, you evaluate the possible k values smaller than the current k 


