### Time 40 min

### Method 1 - Recursion For a Specific Input
[1, 2, 5], input = 5
5=1+1+1+1+1
5=1+1+1+1+2 - not valid
5=1+1+1+2
5=1+1+1+5 - not valid
5=1+1+2+2 - not valid
5=1+2+2
5=1+2+5 - not valid
5=1+5 - not valid
5=2+2+2 - not valid
5=2+5 - not valid
5=5

So first, we assume that the input array is sorted. So we use dp, if suddenly the number
we want to add makes our sum greater than input, we sort jump to the next one. 

#### Note 
It took me 1.5h to debug. I was going in the right direction, but debugging top-down DP (recursive) was just a pain - the logic is daisy chains over daisy chains. 
Another thing is sometimes gdb's controls are weird. Not sure why, but they are confusing. So I might end up spending 
so much more time than I should deciphering them. 

Despite that, with gdb, I finally found where the problem was. 

I made a right move to get close to the solution, but there was still a bug in my code. 
I tried gdb, but that was weird. So I switched to print statements. **Debugging recursive DP needs
you to print pretty much everything to clearly see the pattern.**

**One takeaway is: if gdb is weird, try to use print statements. Print EVERYTHING OUT For recursions**

worst case scenario is O(n*n). **This method is correct, but in Leetcode, this is too slow!!**

### Method 2 Dp w.r.t Coin Combinations
do based on addition of coins. each element means the number of ways.   
```
      0 1   2   3   4   5
[0]     0   0   0   0   0
[0,1]   1   1   1   1   1
[0,1,2] 1   1+1 1+1 1+2  1+2   
```
Note that 1+1 for 2 is 1 from if using only 1 (1+1), plus 1 from if using 0 then 2 (2+0). 
4 is (1+1+1+1) and (2+1+1 and 2+2+0)  
5 is (1+1+1+1+1) and (2+ 2+1) and (2+1+1+1)
**This is the Essence of DP: think how to build your way up to the current step. Another thing is, if building along 
one variable is hard, try a different one.**
Time complexity: O(n*k) Space complexity: S(n*k)

#### Note
0 is an important in the amount values. You have to consider 0, which is when there should be an additional 1 added to the new element. 
Also, there should always be a way for amount= 0. 

