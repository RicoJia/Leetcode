#include <vector>
#include <algorithm>
#include <iterator>
using std::vector;
using std::copy;
using std::back_inserter;

/* 2022-01-07
 * class Solution {
public:
    void sortColors(vector<int>& nums) {
        for(int i = 1; i < nums.size(); ++i){
            for (int j = i; j >= 1; --j){
               if (nums.at(j) < nums.at(j-1)){
                   std::swap(nums.at(j), nums.at(j-1));
               }
            }
        }
    }
};
 */

/* 2022-01-07
 * class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> counts(3, 0);
        for (const auto& num: nums){
            ++counts[num];
        }

        nums.clear();
        for (int i = 0; i<counts.size(); ++i){
            vector<int> temp (counts[i], i);
            nums.insert(nums.end(), temp.begin(), temp.end());
        }
    }
};
*/


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
