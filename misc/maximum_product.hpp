//2022-01-23
// NOT THE BEST: max, min doesn't have to be +/-, just realize that the real max may come from the +/-
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        const int NA = INT_MAX; 
        int hist_max = NA;
        int p_max = NA, p_min=NA; 
        for (int n: nums){
            int a = (p_max == NA)? 1: p_max; 
            int b = (p_min == NA)? 1: p_min;
            int an = a * n, bn = b*n; 
            vector<int> vec = {an, bn, n}; 
            int max = *(std::max_element(vec.begin(), vec.end())); 
            int min = *(std::min_element(vec.begin(), vec.end())); 
                        
            if (hist_max == NA) hist_max = max; 
            else if (max > hist_max) hist_max = max; 
            
            if (max >= 0) p_max = max; 
            else p_max = NA; 
            
            if (min<0) p_min = min; 
            else p_min = NA; 
        }
        
        return hist_max; 
    }
};
