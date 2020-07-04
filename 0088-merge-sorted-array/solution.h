#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int tail_i = m+n-1;
        int nums1_i = m - 1;
        int nums2_i = n - 1;
        while (nums1_i >= 0 && nums2_i >= 0){
            if(nums1.at(nums1_i) > nums2.at(nums2_i)){
                nums1.at(tail_i--) = nums1.at(nums1_i--);
            }
            else{
                nums1.at(tail_i--) = nums2.at(nums2_i--);
            }
        }

        while(nums2_i >= 0){
            nums1.at(tail_i--) = nums2.at(nums2_i--);
        }
    }
};

