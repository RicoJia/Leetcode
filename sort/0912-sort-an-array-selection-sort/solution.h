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
    template <class Comparator>
    void selectionSort(vector<int>& nums, const Comparator& smallers){
        for (int start = 0; start<nums.size(); ++start) {
            int min_index = start;
            for(int i = start;i < nums.size(); ++i){
                if(smallers(nums.at(i), nums.at(min_index)))
                    min_index = i;
            }
            swap(nums.at(start), nums.at(min_index));
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        selectionSort(nums, smallers());
        return nums;
    }
};