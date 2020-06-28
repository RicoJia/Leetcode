#include <vector>
#include <algorithm>
#include <iterator>
using std::vector;
using std::copy;
using std::back_inserter;

/*METHOD 1
 * class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count_arr[] = {0,0,0};
        for(int i: nums){
            ++count_arr[i];
        }
        nums.clear();
        for (int i = 0; i < 3; ++i){
            vector<int> temp(count_arr[i], i);
            copy(temp.begin(),temp.end(), back_inserter(nums));
        }
    }
};*/

#include <iostream>
using std::cout;
using std::endl;

class Solution {
public:
    void sortColors(vector<int>& A) {
        int n = A.size();
        for (int i=0, j=0; i<n; ++i){
            if (A[i] == 0) std::swap(A[i], A[j++]);
            else if (A[i] == 2) std::swap(A[i--], A[--n]);
        }
    }
};