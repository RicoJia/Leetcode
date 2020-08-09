### Time 60 min


### Method 1 - Caching
Imagine you have so many calls to the same function. What do you do? 
You can precompute all the numbers, then return them. 
Like in 1d case, you store the sum till a certain element in every row, then sum up the rows you need. 
Is this called DP? Yes, because DP is to use a previously calculated result to compute
a more complicated one. 

### Method 2 - Caching Smarter
I was on the right track, but I still had this mental constraint on myself, which was to get the sum of square blocks. 
The real good method is for every element in the map, sum up the block that starts at the origin, and ends at that element. 


