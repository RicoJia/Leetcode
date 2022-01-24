#2022-01-12
class Solution:
    def dfs(self, start_id):
        if (self.visit[start_id] != self.UV):
            return
        #real dfs part
        self.visit[start_id] = self.VG

        for i in range (0, self.num):
            if self.g[start_id][i] == 1:
                self.dfs(i)
        self.visit[start_id] = self.VD

    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        self.num = len(isConnected)
        self.VG = -1
        self.UV = 0
        self.VD = 1
        self.visit = [self.UV] * self.num
        self.g = isConnected
        self.count = 0
        for id in range(self.num):
            if self.visit[id] == self.UV:
                self.dfs(id)
                self.count+=1
        return self.count
