#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <algorithm>
using std::for_each;
using std::swap;

class Solution {
public:
    // merge 2 sorted vectors: [start1, mid), [mid, end2) O(m)
    // use pointer here as required by the coding guideline
    void merge(vector<int>* nums_ptr, int start1, int mid, int end2){
        vector<int> temp;
        temp.reserve(end2 - start1);
        int i1 = start1, i2 = mid;
        while(i1!=mid || i2!= end2){
            int to_push = (i1 == mid || ( i2<end2 && (*(nums_ptr)).at(i2) <= (*(nums_ptr)).at(i1)))? (*(nums_ptr)).at(i2++):(*(nums_ptr)).at(i1++);
            temp.push_back(to_push);
        }
        for(auto i = start1; i < end2; ++i){
            (*nums_ptr).at(i) = temp.at(i - start1);
        }
    }

    void merge_sort(vector<int>* nums_ptr, int start, int end){
        if(start + 1 == end) return;
        if(start + 2 == end) {
            if((*nums_ptr).at(start) > (*nums_ptr).at(end-1)) swap((*nums_ptr).at(start), (*nums_ptr).at(end-1));
            return;
        }
        int mid = (start + end)/2 + 1;
        merge_sort(nums_ptr, start, mid);
        merge_sort(nums_ptr, mid, end);
        merge(nums_ptr, start, mid, end);
    }

    vector<int> sortArray(vector<int>& nums) {
        merge_sort(&nums, 0, nums.size());
        return nums;
    }
};