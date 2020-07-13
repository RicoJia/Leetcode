#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <functional>

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
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

