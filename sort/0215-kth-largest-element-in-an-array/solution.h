#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <algorithm>
using std::push_heap;
using std::swap;

//class Solution {
//public:
//    int findKthLargest(vector<int>& nums, int k) {
//        // build a min heap with the largest k values
//        vector<int> smallest_k_vec;
//        smallest_k_vec.reserve(k+1);
//        smallest_k_vec = {nums.begin(), nums.begin() + k};
//        make_heap(smallest_k_vec.begin(), smallest_k_vec.end(), [&](int& a, int& b){ return a > b; });
//
//        for(auto nums_itr = nums.begin() + k; nums_itr < nums.end(); ++nums_itr){
//            if(*nums_itr > smallest_k_vec.at(0)){
//                smallest_k_vec.push_back(*nums_itr);
//                push_heap(smallest_k_vec.begin(), smallest_k_vec.end(), [&](int& a, int& b){ return a > b; });
//                pop_heap(smallest_k_vec.begin(), smallest_k_vec.end(), [&](int& a, int& b){ return a > b; });
//                smallest_k_vec.pop_back();
//            }
//        }
//        return smallest_k_vec.at(0);
//    }
//};


class Solution {
private:

//    {3,2,3,1,2,4,5,5,6}
    //partition and return the position of an element. [start, end)
    // you need to return the position of your final position, because there'd be no way to distinguish the position of each pivot.
    int find_pos(vector<int>& nums, int k, int start, int end){
        if(start + 1 == end || start == end) return start; //means you have single-element subarray, start == end when there is nothing in on one side the previous pivot
        // partition with pivot = last element in the array.
        int actual_pos;
        bool avail_status = false;
        int avail_i = start;

        for(int curr_i = start ; curr_i < end; ++curr_i){
            if(avail_status == true){
                if(nums.at(curr_i) >= nums.at(end-1)){
                    swap(nums.at(curr_i), nums.at(avail_i++));
                }
            }
            else{
                if(nums.at(curr_i)<nums.at(end-1)) avail_status = true;
                else ++avail_i;
            }
        }
        if(avail_i - 1 == k || find_pos(nums, k, start, avail_i -1) == k || find_pos(nums, k, avail_i, end) == k) return k;
        return -1;
    };
public:
    int findKthLargest(vector<int>& nums, int k) {
        find_pos(nums, k-1, 0, nums.size());
        return nums.at(k-1);
    }
};



