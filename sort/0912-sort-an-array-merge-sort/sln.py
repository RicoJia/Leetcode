#2022-01-13
class Solution:
    def merge_s(self, l, r):
        if l == r: 
            return 
        if l+1 == r: 
            if self.n_[l] > self.n_[r]: 
                self.n_[l], self.n_[r] = self.n_[r], self.n_[l]
            return 
        # real part 
        temp = []
        mid = int((l+r)/2)
        self.merge_s(l, mid)
        self.merge_s(mid+1, r)
        # the actual merge part
        l_start = l 
        r_start = mid+1
        while l_start <= mid and r_start<=r:
            if(self.n_[l_start] < self.n_[r_start]): 
                temp.append(self.n_[l_start])
                l_start += 1
            else: 
                temp.append(self.n_[r_start])
                r_start += 1 
        if (l_start <= mid): 
            temp+=(self.n_[l_start: mid +1])
        else: 
            temp+=(self.n_[r_start: r+1])
        self.n_[l:r+1] = temp

    
    def sortArray(self, nums: List[int]) -> List[int]:
        self.n_ = nums
        self.merge_s(0, len(nums) - 1)
        return self.n_
        
