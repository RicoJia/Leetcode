#include <vector>
using std::vector;  

class Solution {
public:
    // regular method
    int missingNumber(vector<int>& nums) {
        int max = nums.size() + 1; 
        vector<bool> vec(max, false); 
        for (auto i:nums){
            vec.at(i) = true; 
        }
        for(int i = 0; i < max; ++i){
            if (vec.at(i) == false)
                return i; 
        }
        return 0;
    }
};
