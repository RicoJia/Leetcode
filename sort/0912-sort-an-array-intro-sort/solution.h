#include <iostream>
using std::cout;
using std::endl;

#include <vector>
#include <algorithm>
using std::vector;
using std::swap;

#include <deque>
using std::deque;

#include <cmath>

class Solution {
    // we want to build a max heap, then swap the top with the tail.
private:

    /* Insertion sort */
    template <class Comparator>
    void insert_into_dq(int element, deque<int>& dq, const Comparator& smallers ){
        auto it_start = dq.begin(), it_end = dq.end();
        while(it_start + 1 != it_end && it_start != it_end){
            auto it_mid = it_start + (it_end - it_start)/2;
            if(*it_mid <= element) it_start = it_mid;
            else it_end = it_mid;
        }
        if(*it_start < element) ++it_start;
        dq.insert(it_start, element);   // because *it_start <= element. you want to insert element in the slot right after it.however,
        // in case of a single-element dq, you have to see if the element is smaller/larger
    }

    /*Quick Sort*/
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

public:
    struct Smallers{
        bool operator()(int a, int b) const{
            return a < b;
        }
    };

    //heapify [i, end)
    template <typename Comparator>
    void heapify(vector<int>& nums, int i, int start, int end, const Comparator& compa){
        int large = i;
        int l = start + 2 * (i-start) + 1, r = start + 2 * (i-start) + 2;
        if(l < end && compa(nums.at(large), nums.at(l))){
            large = l;
        }

        if(r < end && compa(nums.at(large), nums.at(r))){
            large = r;
        }

        if(large != i){
            swap(nums.at(i), nums.at(large));
            heapify(nums, large, start, end, compa);
        }
    }

    // heap sort, we use [start, end)
    template <typename Comparator>
    void heapSort(vector<int>& nums, const int start, const int end, const Comparator& compa){
        // build heap
        for(int i = (start + end)/2 -1; i >= start; --i){
            heapify(nums, i, start, end, compa);
        }

        //pop the largest element, and heapify again and again
        int new_end = end;
        while(new_end > start){
            swap(nums.at(start), nums.at(--new_end));
            heapify(nums, start,  start, new_end, compa);
        }
    }

    /*Insertion Sort*/
    template <class Comparator>
    void insertionSort(vector<int>& nums, const Comparator& smallers){
        deque<int> dq {nums.at(0)};
        for (int start = 1; start<nums.size(); ++start) {
            insert_into_dq(nums.at(start), dq, smallers);
        }
        nums = vector<int> (dq.begin(), dq.end());
    }

    // we use [start, end)
    template<class Comparator>
    void introSort(vector<int>& nums, const int start, const int end, int depth_limit, const Comparator& compa){
        if (nums.size() <= 16) {
            insertionSort(nums, compa);
        }
        else{
            if (depth_limit == 0){
                heapSort(nums, start, end, compa);
            }
            else{   // quicksort
                if (start + 1 == end || start == end ) return;  // you need start == end because partition might be start; start + 1 == end because in regular cases, end = start + 1.
                int partition_i = partition(nums, end - 1, start, end);
                --depth_limit;
                introSort(nums, start, partition_i, depth_limit, compa);
                introSort(nums, partition_i + 1, end, depth_limit, compa);
            }
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        introSort(nums, 0, nums.size(), std::floor(std::log2(nums.size())), Smallers());
        return nums;
    }
};