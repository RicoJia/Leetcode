#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

/*class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int curr_num = nums.at(0);
        for (int i = 0; i < (int)nums.size() - 2; ++i){
            if(nums.at(i) == nums.at(i+2)) {
                nums.erase(nums.begin()+i+2);
                --i;
            }
        }
        return nums.size();
    }
};*/

#include <algorithm>
using std::remove;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int curr_num = nums.at(0);
        auto nums_end = nums.end(); auto nums_itr = nums.begin();
        while(nums_itr + 2 < nums_end){
            if(*nums_itr == *(nums_itr+2)) {
                nums_end = remove(nums_itr+2, nums_end, *nums_itr);
                nums_itr+=2;
            }
            else ++nums_itr;
        }
        return nums_end - nums.begin();
    }
};