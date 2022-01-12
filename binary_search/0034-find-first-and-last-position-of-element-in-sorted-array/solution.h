#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <functional>

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // Method 1
        // auto first_element = std::find(nums.begin(), nums.end(), target);
        // if (first_element == nums.end()) return {-1, -1};
        // int first_i = first_element - nums.begin();
        // std::reverse(nums.begin(), nums.end());
        // auto last_element = std::find(nums.begin(), nums.end(), target);
        // int last_i = nums.size() - (last_element - nums.begin()) -1;
        // return {first_i, last_i};
        
        // Method 2
        if(nums.size()==0) return{-1, -1};

        int l_bound = 0, r_bound = nums.size()-1;
        std::function<int (int lower, int upper)> find_an_index = [&](int lower, int upper){
            if(nums.at(upper) == target) return upper;
            if(nums.at(lower) == target) return lower;
            if (lower == upper || lower + 1 == upper) return -1;    //this is also for nums = {1} target = 0

            int middle_i = (upper + lower)/2;
//            cout<<"middle_i: "<<middle_i<<endl;
            l_bound = lower; r_bound = upper;
            return (nums.at(middle_i) >= target)? find_an_index(lower, middle_i):find_an_index(middle_i, upper);
        };

        int random_index = find_an_index(0, nums.size()-1);
//        cout<<"random index: "<<random_index<<endl;
        if (random_index == -1) return {-1, -1};

        //modify l_bound, r_bound.
        int min_i = random_index, max_i = random_index;

        std::function<void (void)> find_max_i = [&](void){
            //return when the last item is target.
            if(max_i!=r_bound){
                if(nums.at(max_i) == target){
                    if(nums.at(max_i + 1)<=target){
                        max_i = (max_i + r_bound)/2;
                        find_max_i();
                    }
                }
                else{
                    r_bound = max_i;
                    max_i = (random_index + max_i)/2;
                    find_max_i();
                }
            }
        };

        std::function<void (void)> find_min_i = [&](void){
            //return when the first item is target.
            if(min_i!=l_bound){
                if(nums.at(min_i) == target && nums.at(min_i - 1) == target){
                    min_i = (min_i + l_bound)/2;
                    find_min_i();
                }
                else if (nums.at(min_i) < target){
                    l_bound = min_i;
                    min_i = (random_index + min_i)/2;
                    find_min_i();
                }
            }
        };

        find_max_i();
        find_min_i();

        return {min_i, max_i};
    }
};

// METHOD 3 - for loop instead of recursion
// class Solution {
// public:
//
//     vector<int> searchRange(vector<int>& nums, int target) {
//         int head_i = 0; int tail_i = nums.size()-1;
//         int one_target_i = -1;
//
//         // corner case: [5, 7], 6, med = 0.
//         while (head_i < tail_i){
//             int med = (head_i + tail_i)/2;
//             //TODO
//             cout<<med<<endl;
//
//             if (nums.at(med) == target){
//                 one_target_i = med;
//                 break;
//             }
//             else if (nums.at(med) < target){
//                 head_i = med;
//             }
//             else{
//                 tail_i = med;
//             }
//
//             if (head_i + 1 == tail_i){
//                 if (nums.at(tail_i) == target)
//                     one_target_i = tail_i;
//                 else if (nums.at(head_i) == target)
//                     one_target_i = head_i;
//                 break;
//             }
//         }
//
//
//         if (head_i == tail_i){
//             if (nums.at(head_i) == target){
//                 one_target_i = head_i;
//             }
//         }
//
//         if (one_target_i == -1) return {-1, -1};
//
//         // get head
//         for (; (head_i != one_target_i) && (nums.at(head_i) < target); head_i++){}
//         for (; (tail_i != one_target_i) && (nums.at(tail_i) > target); tail_i--){}
//         return {head_i, tail_i};
//
//     }
// };
