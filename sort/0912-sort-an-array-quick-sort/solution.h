#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <algorithm>
using std::for_each;
using std::swap;

class Solution {
private:
    struct smallers{
        bool operator()(int a, int b) const{
            return a < b;
        }
    };
public:
    // also returns the position of the pivot
    int partition(vector<int>& nums, const int to_find_index, const int start, const int end){
        int to_swap_i = start, to_check_i = start + 1;
        for(; to_check_i < end; ++to_check_i){
            if(nums.at(to_swap_i) < nums.at(to_find_index)) ++to_swap_i;
            if(to_swap_i < to_check_i && nums.at(to_check_i) < nums.at(to_find_index)){
                swap(nums.at(to_swap_i++), nums.at(to_check_i));
            }

        }

        if (nums.at(to_swap_i) < nums.at(to_find_index)) ++to_swap_i;   //because you don't know if the first element in this array is larger.
        swap(nums.at(to_swap_i), nums.at(to_find_index));
        return to_swap_i;
    }

    //vector to sort is [start, end)
    template<class Comparator>
    void quickSort(vector<int> &nums, const Comparator &compa, const int start, const int end) {
        if (start + 1 == end || start == end ) return;

        int partition_i = partition(nums, end - 1, start, end);
        quickSort(nums, compa, start, partition_i);
        quickSort(nums, compa, partition_i + 1, end);       // here if partition_i is the last element. for the next iteration you might get start == end;
    }

    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, smallers(), 0, nums.size());
        return nums;
    }
};