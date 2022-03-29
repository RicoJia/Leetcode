#include "solution.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
int maxLength(vector<int> a, int k) {
    // std::sort(a.begin(), a.end()); 
    // [0, sum_0...]
    std::vector<int>sums(a.size() + 1, 0); 
    for (int i = 0; i < a.size(); ++i){
        sums.at(i+1) = sums.at(i) + a[i]; 
    } 
    
    int start = 0; 
    auto fast_forward = [&](int n){
        while (sums[n] - sums[start] > k) ++start; 
    };
    int longest = 0; 
    for (int n = 1; n < sums.size(); ++n){
        fast_forward(n); 
        longest = std::max(longest, n -start); 
    }
    return longest; 
}

int main(){
    Solution s;
    vector<int> a = {74, 659, 931, 273, 545, 879, 924, 710, 441, 166, 493, 43, 988, 504, 328, 730, 841, 613, 304, 170, 710, 158, 561, 934, 100, 279, 817, 336, 98, 827, 513, 268, 811, 634, 980, 150, 580, 822, 968, 673, 394, 337, 486, 746, 229, 92, 195, 358, 2, 154, 709, 945, 669, 491, 125, 197, 531, 904, 723, 667, 550}; 
    int ret = maxLength(a, 22337);
    cout<<"ret: "<<ret<<" | expect: "<<46<<endl;

}
