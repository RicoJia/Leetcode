#include <iostream>
using std::cout;
using std::endl;

#include <vector>
#include <algorithm>
using std::vector;
using std::swap;

class Solution {
    // we want to build a max heap, then swap the top with the tail.
public:
    struct smallers{
        bool operator()(int a, int b) const{
            return a < b;
        }
    };

    //heapify
    template <typename comparator>
    void heapify(vector<int>& nums, int i, int size, const comparator& compa){
        int large = i;
        int l = 2 * i + 1, r = 2 * i + 2;
        if(l < size && compa(nums.at(large), nums.at(l))){
            large = l;
        }

        if(r < size && compa(nums.at(large), nums.at(r))){
            large = r;
        }

        if(large != i){
            swap(nums.at(i), nums.at(large));
            heapify(nums, large, size, compa);
        }

    }

    // heap sort
    template <typename comparator>
    void heapSort(vector<int>& nums, const comparator& compa){
        // build heap
        for(int i = (nums.size())/2 -1; i >= 0; --i){
            heapify(nums, i, nums.size(), compa);
        }

        //pop the largest element, and heapify again and again
         int size = nums.size();
         while(size > 1){
             swap(nums.at(0), nums.at((size--) - 1));
             heapify(nums, 0, size, compa);
         }
    }

    vector<int> sortArray(vector<int>& nums) {
        heapSort(nums, smallers());
        return nums;
    }
};