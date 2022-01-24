# 2022-01-18
class Solution:
    def possibleBipartition(self, n: int, dislikes: List[List[int]]) -> bool:
        # Build bi-directional edge list, because we need to check the dislike of items smaller than the current index. 
        self.full_edges = [[] for _ in range(n+1)]        #

        for d in dislikes:
            self.full_edges[d[0]].append(d)
            self.full_edges[d[1]].append(d[::-1])

        self.colors = [0 for _ in range(n+1)]
        for i in range(1, n+1):
            if self.colors[i] == 0:
                if self.dfs(i,i) == False:
                    return False
        return True

    def dfs(self, id, desired_color):
        if self.colors[id] == desired_color:
            return True
        elif self.colors[id] == -desired_color:
            return False
        self.colors[id] = desired_color

        for d in self.full_edges[id]:
            next_id = d[1]
            if self.dfs(next_id, -desired_color) == False:
                return False
        return True

