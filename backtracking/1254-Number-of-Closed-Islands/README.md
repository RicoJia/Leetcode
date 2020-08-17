### Time 20 min

### Method 1 DFS
So do dfs on every single **Unexplored island**, try to find the whole big island. If the island is connected to an island marked "boundary", then skip. 
Else, mark this island as"explored", and count it in.  
**For the sake of code conciseness, you don't need "boundary" state, as one island will evaluate a boundary island only once. Also, if your current patch meets a previously stopped
 at an unfinished border patch or an isolate patch, you simply don't count the current patch in. **
