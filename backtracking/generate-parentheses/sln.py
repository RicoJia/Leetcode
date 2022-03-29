# (Closure), closure() are both valid
# N = 0: ""
# N = 1: ("")
# N = 2: (("")); ("")()
# N = 3: (((""))), (("")()) left = 2, right = 0;((""))("") left = 1, right =1;()(("")), ()("")() left = 0, right = 2
class Solution(object):
    def generateParenthesis(self, N):
        if N == 0: return ['']
        ans = []
        for c in xrange(N):
            for left in self.generateParenthesis(c):
                for right in self.generateParenthesis(N-1-c):
                    ans.append('({}){}'.format(left, right))
        return ans

s = Solution()
sln = s.generateParenthesis(2)
print(sln)
