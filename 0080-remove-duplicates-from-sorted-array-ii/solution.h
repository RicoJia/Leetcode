#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

// Lessons learned: 
//  - remove needs to work with end, then use the new end: 
//      end = std::remove(beg, end, val); // Not vec.end()
//  - vector::erase() also exists
//  - Bidirectional itrs: you can do itr+2. 
//  - std::distance(beg, end)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for (int i = 0; i < (int)nums.size() - 2; ++i){
            if(nums.at(i) == nums.at(i+2)) {
                nums.erase(nums.begin()+i+2);
                --i;
            }
        }
        return nums.size();
    }
};


// 2022-01-11
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto end = nums.end();
        for(auto itr = nums.begin(); itr+2 < end;){
            if (*itr == *(itr+2)){
                end = std::remove(itr+2, end, *itr);
                itr += 2;
            }
            else itr += 1;
        }
        return std::distance(nums.begin(), end);
    }
};
