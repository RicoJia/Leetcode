### Time 40 min

### Method 1 - DP
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

### Note 
It took me 1.5h to debug. I was going in the right direction, but debugging top-down DP (recursive) was just a pain - the logic is daisy chains over daisy chains. 
Another thing is sometimes gdb's controls are weird. Not sure why, but they are confusing. So I might end up spending 
so much more time than I should deciphering them. 

Despite that, with gdb, I finally found where the problem was. 

I made a right move to get close to the solution, but there was still a bug in my code. 
I tried gdb, but that was weird. So I switched to print statements. **Debugging recursive DP needs
you to print pretty much everything to clearly see the pattern.**

**One takeaway is: if gdb is weird, try to use print statements. Print EVERYTHING OUT For recursions**

worst case scenario is O(n*n). **This method is correct, but in Leetcode, this is too slow!!**

### Method 2

