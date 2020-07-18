#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <algorithm>
using std::swap;

class Solution {
    // we want to build a max heap, then swap the top with the tail.
private:
    struct smallers{
        bool operator()(int a, int b)const{
            return a < b;
        }
    };

public:
    template<typename comparator>
    void bubbleSort(vector<int>&nums, const comparator& compa) const{
        bool is_sorted = false;
        while (is_sorted == false){
            is_sorted = true;
            for(auto i = nums.begin(); i < nums.end()-1; ++i){
                if(compa(*(i+1), *i)) {
                    swap(*i, *(i+1));
                    if(is_sorted == true)
                        is_sorted = false;
                }
            }
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        bubbleSort(nums, smallers());
        return nums;
    }
};