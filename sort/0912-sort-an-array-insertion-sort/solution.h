#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <algorithm>
using std::for_each;
using std::swap;

#include <deque>
using std::deque;

class Solution {
private:
    struct smallers{
        bool operator()(int a, int b) const{
            return a < b;
        }
    };


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

    //    template <class Comparator>
//    void insert_into_dq(int element, deque<int>& dq, const Comparator& smallers ){
//        auto it = dq.begin();
//        for(; it!= dq.end() && *it < element; ++it){}
//        if(it == dq.end()) it = dq.end();
//        dq.insert(it, element);
//    }

public:
    template <class Comparator>
    void insertionSort(vector<int>& nums, const Comparator& smallers){
        deque<int> dq {nums.at(0)};
        for (int start = 1; start<nums.size(); ++start) {
            insert_into_dq(nums.at(start), dq, smallers);
        }
        nums = vector<int> (dq.begin(), dq.end());
    }

    vector<int> sortArray(vector<int>& nums) {
        insertionSort(nums, smallers());
        return nums;
    }
};